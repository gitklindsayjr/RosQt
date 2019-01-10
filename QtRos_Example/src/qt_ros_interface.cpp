/****************************************************************************
 *  Copyright (C) 2017 Ken Lindsay
 *
 *  This is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *****************************************************************************/
#include <QDebug>
#include <unistd.h>
#include "qt_ros_interface.h"
#include "cmd_status.h"

QtRosInterface::QtRosInterface(QWidget *parent)
{
    this->parent = parent;
    connect(this, SIGNAL(acknowledge()), parent, SLOT(acknowledge()));
    connect(this, SIGNAL(serialIoString(QString)), parent, SLOT(serialIoString(QString)));
    connect(this, SIGNAL(serialIoFloat(float)), parent, SLOT(serialIoFloat(float)));
    connect(this, SIGNAL(serialIoInteger(int)), parent, SLOT(serialIoInteger(int)));
    connect(this, SIGNAL(redLedState(bool)), parent, SLOT(redLedState(bool)));
    connect(this, SIGNAL(sendMessage(QString)), parent, SLOT(receiveMessage(QString)));
}
QtRosInterface::~QtRosInterface(void)
{
}
void QtRosInterface::setLedState(bool state)
{
    std::string str = START_DELIMITER;
    if(state)
        str+= RED_LED_ON_STR;
    else
        str+= RED_LED_OFF_STR;
    str+= END_DELIMITER;
    txMessage(str);
}
void QtRosInterface::toggleLedState(void)
{
    std::string str = START_DELIMITER;
    str+= RED_LED_TOGGLE_STR;
    str+= END_DELIMITER;
    txMessage(str);
}

void QtRosInterface::setStringCommand(std::string strMsg)
{
    std::string str = "<SS," + strMsg + ">";
    txMessage(str);
}
void QtRosInterface::setFloatCommand(std::string value)
{
    std::string str = "<SF," + value + ">";
    txMessage(str);
}
void QtRosInterface::setIntegerCommand(std::string value)
{
    std::string str = "<SI," + value + ">";
    txMessage(str);
}
void QtRosInterface::getStringCommand(void)
{
    std::string str = "<GS>";
    txMessage(str);
}
void QtRosInterface::getFloatCommand(void)
{
    std::string str = "<GF>";
    txMessage(str);
}
void QtRosInterface::getIntegerCommand(void)
{
    std::string str = "<GI>";
    txMessage(str);
}
void QtRosInterface::handleIo(std::string parameterStr, int token)
{
    QString message;
    size_t length, delimitPos, commaPos;
    int   intValue;
    float value;

    delimitPos = parameterStr.find(END_DELIMITER); // Look for the end delimiter
    if(delimitPos == std::string::npos) // Bad parameter string no end
        return;
    parameterStr.assign(parameterStr, 0, delimitPos);
    if(!parameterStr.empty())
    {
        commaPos = parameterStr.find(',');
        if(commaPos == std::string::npos) // Bad parameter string no comma
            return;
        commaPos++;
        length = delimitPos - commaPos;
        parameterStr = parameterStr.substr(commaPos, length);
    }
    switch(token)
    {
        case NO_COMMAND:
            break;
        case QUIT_CMD:
        case RESTART_CMD:
            break; // Currently do nothing
        case ACKNOWLEDGE:
            acknowledge();
            break;
        case RED_LED_TOGGLE_MSG:
            intValue = std::stoi(parameterStr, nullptr, 10);
            redLedState((bool)intValue);
            break;
        case STRING_TYPE_MESSAGE:
            message = QString::fromStdString(parameterStr);
            serialIoString(message);
            break;
        case INTEGER_TYPE_MESSAGE:
            intValue = std::stoi(parameterStr, nullptr, 10);
            serialIoInteger(intValue);
            break;
        case FLOAT_TYPE_MESSAGE:
            value = std::stof(parameterStr);
            serialIoFloat(value);
            break;
        default:
            break;
      }
}
void QtRosInterface::parseInput(void)
{
    std::string inputStr = rxMessage();
    int      token = 0, state=START_PARSING;
    int      foundPos;
#ifdef DEBUG
    qDebug() << QString::fromStdString(rxMessage());
#endif
    sendMessage(QString::fromStdString(rxMessage()));

    while(inputStr.size() > 0)
    {
        switch(state)
        {
            case START_PARSING: // Find start delimiter
                foundPos = inputStr.find(START_DELIMITER);
                if(foundPos == -1) // Invalid command
                    return;
                state=PARSE;
                inputStr.assign(inputStr, foundPos + 1, std::string::npos);
                break;
            case PARSE:
                token = inputStr[0]<<8;
                token|= inputStr[1];
                state=FOUND_TOKEN;
                inputStr.assign(inputStr, 2, std::string::npos);
                break;
            case FOUND_TOKEN:
                foundPos = inputStr.find(END_DELIMITER);
                if(foundPos == -1)
                    return; // Invalid command
                handleIo(inputStr, token);
                inputStr.assign(inputStr,foundPos + 1, std::string::npos);
                state=START_PARSING;
                break;
            default:
                break;
        }
    }
}
