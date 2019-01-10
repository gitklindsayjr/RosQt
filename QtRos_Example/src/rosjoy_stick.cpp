/*
 * joy_stick.cpp
 *
 *  Created on: Apr 11, 2017
 *      Author: pops
 */
#include "rosjoy_stick.h"
RosJoyStick::RosJoyStick(void)
{
    for(int i = 0; i<NUM_AXIS; i++)
        joystick.axisValues[i] = 0;
	for(int i=0; i<NUM_BUTTONS; i++)
        joystick.buttonStates[i] = false;
    ros::NodeHandle nh_;                      // Create node object nh
    joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &RosJoyStick::joyCallback, this);
	// Initialize joy stick default axis and scaling, Thrust master
	nh_.param("axis_linear_x",   linear_x_,  DEFAULT_AXIS_LINEAR_X);
	nh_.param("axis_linear_y",   linear_y_,  DEFAULT_AXIS_LINEAR_Y);
	nh_.param("axis_linear_z",   linear_z_,  DEFAULT_AXIS_LINEAR_Z);
	nh_.param("axis_angular_z",  angular_z_, DEFAULT_AXIS_ANGULAR_Z);
	nh_.param("scale_linear_x",  l_scale_x_, DEFAULT_SCALE_LINEAR_X);
	nh_.param("scale_linear_y",  l_scale_y_, DEFAULT_SCALE_LINEAR_Y);
	nh_.param("scale_linear_z",  l_scale_z_, DEFAULT_SCALE_LINEAR_Z);
	nh_.param("scale_angular_z", a_scale_z_, DEFAULT_SCALE_ANGULAR_Z);
	nh_.param("deadzone", dead_zone_, DEFAULT_DEAD_ZONE);
}
joystick_t RosJoyStick::getRosJoystick(void)
{
    return joystick;
}

bool RosJoyStick:: getRosButton(int button)
{
    return joystick.buttons[button];
}
bool RosJoyStick:: getRosButtonState(int button)
{
    return joystick.buttonStates[button];
}
double RosJoyStick::getRosAxisValue(int axis)
{
    return joystick.axisValues[axis];
}

void RosJoyStick::joyCallback(const sensor_msgs::Joy::ConstPtr &joy)
{
	ts_ = joy->header;
    joystick.seconds = ts_.stamp.sec;
    joystick.nanosec = ts_.stamp.nsec;
	// Save time stamp info
	for(int i=0; i<NUM_AXIS; i++)
        joystick.axisValues[i] = joy->axes[i];
	for(int i=0; i<NUM_BUTTONS; i++)
	{
        joystick.buttons[i] = joy->buttons[i];
        if(!joystick.buttonStates[i] && joy->buttons[i])
            joystick.buttonStates[i] = true;
        else if(joystick.buttonStates[i] && joy->buttons[i])
            joystick.buttonStates[i] = false;
	}
}

RosJoyStick::~RosJoyStick(void){}


