#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTimer>
#include <qt_ros_interface.h>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    enum ackEvents_ { GET_STRING, GET_FLOAT, GET_INTEGER, SET_LED, NONE };
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QtRosInterface *rosInterface;
    QProcess *rosrunJoyProcess;
    QProcess *rosrunIoProcess;
    QTimer   *loopTimer; // Emulates ros loop timer
    QTimer   *ackTimer;  // AckEvent timer
    void joyStickValues(joystick_t joystick);
public slots:
    void loop(void);
    void ackTimeout(void);  // Handles commands to be sent on acknowledge true
    void acknowledge(void); // Captures acknowledge signal
    void serialIoString(QString message);
    void serialIoFloat(float value);
    void serialIoInteger(int intValue);
    void redLedState(bool state);
    void receiveMessage(QString msg);
private slots:
    void on_lineEdit_string_editingFinished(void);
    void on_lineEdit_float_editingFinished(void);
    void on_lineEdit_integer_editingFinished(void);
    void on_pushButton_string_clicked(void);
    void on_pushButton_float_clicked(void);
    void on_pushButton_integer_clicked(void);
    void on_radioButton_ledOn_clicked(bool state);
    void on_radioButton_ledOff_clicked(bool state);
    void on_pushButton_ledToggle_clicked(void);
private:
    bool ackFlag; // Acknowledge flag, set true when acknowledged
    int ackEvent; // XX command to be sent
    int ackCount; // Wait counts before error
};

#endif // MAINWINDOW_H
