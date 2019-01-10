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

#ifndef ROSJOY_STICK_H_
#define ROSJOY_STICK_H_
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_msgs/Header.h>

#define DEFAULT_NUM_OF_BUTTONS          16
#define DEFAULT_AXIS_LINEAR_X           1
#define DEFAULT_AXIS_LINEAR_Y           1
#define DEFAULT_AXIS_LINEAR_Z           2
#define DEFAULT_AXIS_ANGULAR_Z          3
#define DEFAULT_AXIS_ANGULAR_X          4
#define DEFAULT_SCALE_LINEAR_X          -1.0
#define DEFAULT_SCALE_LINEAR_Y          1.0
#define DEFAULT_SCALE_LINEAR_Z          1.0
#define DEFAULT_SCALE_ANGULAR_Z         1.0
#define DEFAULT_SCALE_ANGULAR_X         1.0
#define DEFAULT_DEAD_ZONE               .05

enum _buttons { GREEN, RED, BLUE, ORANGE, LR, RR, BACK, START, BTN_UNDEFINED, NUM_BUTTONS };
enum _axis { LEFT_X, LEFT_Y, LT, RIGHT_X, RIGHT_Y, RT, HAT_X, HAT_Y, AXIS_UNDEFINED, NUM_AXIS };

typedef struct
{
    bool   buttonStates[NUM_BUTTONS];
    bool   buttons[NUM_BUTTONS];
    double axisValues[NUM_AXIS];
    unsigned seconds;
    unsigned nanosec;

} joystick_t;

class RosJoyStick {
	public:
        RosJoyStick(void);
		std_msgs::Header getTimeStamp(void ){ return ts_; }
        joystick_t getRosJoystick(void);
		bool   getRosButtonState(int button);
		bool   getRosButton(int button);
		double getRosAxisValue(int axis);
        ~RosJoyStick();
    public:
        joystick_t joystick;
    private:
		int    linear_x_,  linear_y_, linear_z_, angular_z_;
		double l_scale_x_, l_scale_y_, l_scale_z_, a_scale_z_;
		double dead_zone_;
		void   joyCallback(const sensor_msgs::Joy::ConstPtr &joy);
		ros::Subscriber joy_sub_;
        std_msgs::Header ts_; // Time stamp
};


#endif /* ROSJOY_STICK_H_ */
