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
