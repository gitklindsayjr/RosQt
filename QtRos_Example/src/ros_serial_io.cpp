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

#include "ros_serial_io.h"
#include <ros/publisher.h>

/* Received messages are responses to published messages, 1 message at a time */
#define QUEUE_SIZE              1 // No buffering of messages one at a time
RosSerialIo::RosSerialIo()
{
    msgReceived =    false;
    msgTransmitted = false;
    NodeHandle nh_; // Create node object nh
    serialIo_sub = nh_.subscribe<std_msgs::String>("msp432_pub", QUEUE_SIZE, &RosSerialIo::serialIoCallback, this);
    serialIo_pub = nh_.advertise<std_msgs::String>("qt_pub", QUEUE_SIZE);
}
void RosSerialIo::serialIoCallback(const std_msgs::String::ConstPtr &msg)
{
//    if(msgReceived)
//        return;
    rxMsg = msg->data;
    msgReceived = true;
}
std::string RosSerialIo::rxMessage(void)
{
    msgReceived = false; // Message is being handled
    return rxMsg;
}
void RosSerialIo::txMessage(std::string message)
{
    std_msgs::String stdMsg;
    txMsg = message;
    stdMsg.data = message;
    serialIo_pub.publish(stdMsg);
    msgTransmitted = true; // Message was sent
}
RosSerialIo::~RosSerialIo() {}
