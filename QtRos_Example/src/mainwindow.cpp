#include <QMessageBox>
#include <ros/ros.h>
#include <unistd.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

/* To use this example in a terminal execute roscore command first:
 * $ roscore
 * # and
 * # then run the joystick node
 * $ rosrun joy /joy_node
 * # or
 * # in "QtRos_Example.pro" uncomment the defines statememt
 * # "#DEFINES ++ ROSRUN_JOYSTICK" which will launch the rosrun process
 * # and
 * # then run the serial_node
 * $ rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0
 * # or
 * # in "QtRos_Example.pro" uncomment the defines statememt
 * # "#DEFINES ++ ROSRUN_SERIAL_IO" which will launch the rosrun process
 *
 */

#define ROS_SPIN_TIME        100  // 100 ms for msp432 spin cycle time
#define ACK_MAX_TIME         2000 // 2000 ms
#define ACK_COUNT            (ACK_MAX_TIME/ROS_SPIN_TIME)

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/ros_icon.png"));
#ifdef ROSRUN_JOYSTICK
    QStringList joyArgs = { "joy", "joy_node" };
    rosrunJoyProcess = new QProcess(parent);
    rosrunJoyProcess->start("rosrun", joyArgs);
    rosrunJoyProcess->waitForStarted(1000); // Wait 1 second
#endif
#ifdef ROSRUN_SERIAL_IO
    QStringList serIoArgs = { "rosserial_python", "serial_node.py", "_port:=/dev/ttyACM0"};
    rosrunIoProcess = new QProcess(parent);
    rosrunIoProcess->start("rosrun", serIoArgs);
    rosrunIoProcess->waitForStarted(1000); // Wait 1 second
#endif
    ui->setupUi(this);
    rosInterface = new QtRosInterface(this);
    loopTimer = new QTimer(this);
    ackTimer = new QTimer(this);
    connect(loopTimer, SIGNAL(timeout()), this, SLOT(loop()));
    connect(ackTimer, SIGNAL(timeout()), this, SLOT(ackTimeout()));
    loopTimer->start(ROS_SPIN_TIME); // Loop timer started 100ms interval
    ackFlag = false;    // Allow sufficient time for interface
    ackCount = -10;     // to intialize before setting LED
    ackEvent = SET_LED; // by letting the ack timer to timeout
    ackTimer->start(ROS_SPIN_TIME); // Start timer
}
void MainWindow::loop(void)
{
    if(!ros::ok())
        return;
    ros::spinOnce();
#ifdef ROSRUN_JOYSTICK
    joystick_t joystick;
    joystick = rosInterface->getRosJoystick();
    joyStickValues(joystick); // Signal main GUI
#endif
#ifdef ROSRUN_SERIAL_IO
    if(rosInterface->getMsgReceived())
        rosInterface->parseInput();
#endif
}
void MainWindow::ackTimeout(void)
{   // SET type commands need acknowledgement before sending GET type commands
    if(ackFlag == true)
    {   // The last command has been acknowledged, OK to send
        ackTimer->stop(); // Stop our timer
        ackCount = 0;     // and clear our time out counter
        switch(ackEvent)
        {   // Send the GET command, based on previously set ackEvent
            case GET_STRING:  rosInterface->getStringCommand(); break;
            case GET_FLOAT:   rosInterface->getFloatCommand();  break;
            case GET_INTEGER :rosInterface->getIntegerCommand(); break;
        }
    }
    else if(ackCount >= ACK_COUNT)
    {   // Timed out
        ackTimer->stop(); // Stop the timer
        ackFlag = true;   // Reset our acknowledge flag to allow GET type commands
        ackCount = 0;     // Clear our counter
        if(ackEvent == SET_LED)
        {
            rosInterface->setLedState(true);
            ui->radioButton_ledOn->setChecked(true);
        }
        else
            QMessageBox::warning(this, "ERROR: Timed out", "Interface failed to acknowledge command"); // Display this message
    }
    else
        ackCount++; // Count the number of times we spin here
}
MainWindow::~MainWindow()
{
    delete ui;
    delete rosInterface;
#ifdef ROSRUN_JOYSTICK
    rosrunJoyProcess->terminate();
    rosrunJoyProcess->waitForFinished();
    delete rosrunJoyProcess;
#endif
#ifdef ROSRUN_SERIAL_IO
    rosrunIoProcess->terminate();
    rosrunIoProcess->waitForFinished();
    delete rosrunIoProcess;
#endif
}
void MainWindow::acknowledge()
{   // Received an acknowledge from the interface
    ackFlag = true;
}
void MainWindow::serialIoString(QString message)
{   // Received a string message from the interface
    ui->lineEdit_string->setText(message);
}
void MainWindow::serialIoFloat(float value)
{   // Received a float from the interface
    QString qStr;
    qStr = QString::number(value, 'g', 3);
    ui->lineEdit_float->setText(qStr);
}
void MainWindow::serialIoInteger(int intValue)
{   // Received a integer from the interface
    QString qStr;
    qStr = QString::number(intValue);
    ui->lineEdit_integer->setText(qStr);
}
void MainWindow::redLedState(bool state)
{   // Received state for Red LED
    ui->radioButton_ledOff->setChecked(!state);
    ui->radioButton_ledOn->setChecked(state);
}
void MainWindow::on_radioButton_ledOn_clicked(bool state)
{
    rosInterface->setLedState(state);
}
void MainWindow::on_radioButton_ledOff_clicked(bool state)
{
    rosInterface->setLedState(!state);
}
void MainWindow::on_pushButton_ledToggle_clicked(void)
{
    rosInterface->toggleLedState();
}
void MainWindow::on_lineEdit_string_editingFinished(void)
{   // Editing is finished, ENTER pressed or lost focus to other ui object
    std::string str;
    QString strMsg = ui->lineEdit_string->text();
    str = strMsg.toStdString();
    ackFlag = false;  // SET commands need to be acknowledged when losing focus
    rosInterface->setStringCommand(str);
}
void MainWindow::on_lineEdit_float_editingFinished(void)
{   // Editing is finished, ENTER pressed or lost focus to other ui object
    std::string str;
    QString strMsg = ui->lineEdit_float->text();
    str = strMsg.toStdString();
    ackFlag = false;  // SET commands need to be acknowledged when losing focus
    rosInterface->setFloatCommand(str);
}
void MainWindow::on_lineEdit_integer_editingFinished(void)
{   // Editing is finished, ENTER pressed or lost focus to other ui object
    std::string str;
    QString strMsg = ui->lineEdit_integer->text();
    str = strMsg.toStdString();
    ackFlag = false;  // SET commands need to be acknowledged when losing focus
    rosInterface->setIntegerCommand(str);
}
void MainWindow::on_pushButton_string_clicked(void)
{   // GET type command that expects a previously SET command
    if(!ackFlag)
    {   // If acknowledge is required register the event
        ackEvent = GET_STRING; // Our GET command ID
        ackCount = 0;          // Clear our time out counter
        ackTimer->start(ROS_SPIN_TIME); // No acknowledgement required, just do it now
    }
    else
        rosInterface->getStringCommand();
}
void MainWindow::on_pushButton_float_clicked(void)
{   // GET type command that expects a previously SET coomand
    if(!ackFlag)
    {   // SET was sent wait on the acknowledgement
        ackEvent = GET_FLOAT; // Our GET command ID
        ackCount = 0;         // Clear our time out counter
        ackTimer->start(ROS_SPIN_TIME); // Start our acknowledgement timer
    }
    else
        rosInterface->getFloatCommand(); // No acknowledgement required, just do it now
}
void MainWindow::on_pushButton_integer_clicked(void)
{   // GET type command that expects a previously SET command
    if(!ackFlag)
    {   // SET was sent wait on the acknowledgement
        ackEvent = GET_INTEGER; // Our GET command ID
        ackCount = 0;           // Clear our time out counter
        ackTimer->start(ROS_SPIN_TIME); // No acknowledgement required, just do it now
    }
    else
        rosInterface->getIntegerCommand();
}
void MainWindow::joyStickValues(joystick_t joystick)
{
    QString qStr;
    bool    state;
    for(int i=0; i<NUM_AXIS; i++)
    {
        qStr = QString::number(joystick.axisValues[i], 'f', 3);
        switch(i)
        {
            case LEFT_X:  ui->lineEdit_leftX->setText(qStr);  break;
            case LEFT_Y:  ui->lineEdit_leftY->setText(qStr);  break;
            case RIGHT_X: ui->lineEdit_rightX->setText(qStr); break;
            case RIGHT_Y: ui->lineEdit_rightY->setText(qStr); break;
            case LT:     ui->lineEdit_LT->setText(qStr);      break;
            case RT:     ui->lineEdit_RT->setText(qStr);      break;
            case HAT_X:  ui->lineEdit_hatX->setText(qStr);    break;
            case HAT_Y:  ui->lineEdit_hatY->setText(qStr);    break;
        }
    }
    for(int i=0; i<NUM_BUTTONS; i++)
    {
        state = joystick.buttonStates[i];
        switch(i)
        {
            case GREEN:  ui->radioButton_green->setChecked(state);  break;
            case RED:    ui->radioButton_red->setChecked(state);    break;
            case BLUE:   ui->radioButton_blue->setChecked(state);   break;
            case ORANGE: ui->radioButton_orange->setChecked(state); break;
            case LR:     ui->radioButton_LR->setChecked(state);     break;
            case RR:     ui->radioButton_RR->setChecked(state);     break;
            case BACK:   ui->radioButton_back->setChecked(state);   break;
            case START:  ui->radioButton_start->setChecked(state);  break;
        }
    }
    qStr = QString::number(joystick.seconds);
    ui->lineEdit_seconds->setText(qStr);
    qStr = QString::number(joystick.nanosec);
    ui->lineEdit_nanosec->setText(qStr);
}
void MainWindow::receiveMessage(QString msg)
{
    statusBar()->showMessage(msg);
}
