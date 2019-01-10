#ifndef QTROSINTERFACE_H
#define QTROSINTERFACE_H

#include <QWidget>
#include <QTimer>
#include <string>
#include <rosjoy_stick.h>
#include "ros_serial_io.h"

enum states_    { START_PARSING, PARSE, FOUND_TOKEN };
enum responses_ { DO_NOTHING, INITIALIZE_PINS, GET_STATUS, GET_DATA, SET_INPUT };
enum errors_    { NO_ERROR, RECEIVE_ERROR, RECEIVE_LOOP_PARSE_OVERRUN, RECEIVE_FG_PARSE_DELIMIT };

class QtRosInterface : public QWidget, public RosJoyStick, public RosSerialIo
{
    Q_OBJECT
public:
    QtRosInterface(QWidget *parent);
    ~QtRosInterface(void);
    void setLedState(bool state);
    void toggleLedState(void);
    void setStringCommand(std::string strMsg);
    void setFloatCommand(std::string value);
    void setIntegerCommand(std::string value);
    void getStringCommand(void);
    void getFloatCommand(void);
    void getIntegerCommand(void);
    void parseInput(void);
private:
    QWidget *parent;
    void handleIo(std::string parameterStr, int token);
signals:
    void acknowledge(void);
    void serialIoString(QString strMsg);
    void serialIoFloat(float value);
    void serialIoInteger(int intValue);
    void redLedState(bool state);
    void sendMessage(QString msg);
private:
};
#endif // QTROSINTERFACE_H
