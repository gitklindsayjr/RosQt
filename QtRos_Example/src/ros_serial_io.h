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
#ifndef ROSSUB_SERIAL_IO_H
#define ROSSUB_SERIAL_IO_H

/* This class subscribes to the ros python serial IO and receives std_msg strings */
#include <string>
#include <ros/ros.h>
#include <std_msgs/String.h>

using namespace ros;

class RosSerialIo
{
public:
    RosSerialIo(void);
    std::string rxMessage(void);
    Subscriber serialIo_sub;
    Publisher  serialIo_pub;
    void txMessage(std::string);
    bool getMsgReceived(void) { return msgReceived; }
    bool getMsgTransmitted(void) { return msgTransmitted; }
    ~RosSerialIo();
private:
    bool msgReceived;
    bool msgTransmitted;
    std::string rxMsg;
    std::string txMsg;
    void serialIoCallback(const std_msgs::String::ConstPtr &msg);
};
#endif // ROSSUB_SERIAL_IO_H
