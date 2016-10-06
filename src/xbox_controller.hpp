#pragma once

#include <WPILib.h>

class Xbox_Controller {
public:
		Xbox_Controller(uint32_t port);
		
		float get_left_x();
		float get_left_y();
		float get_right_x();
		float get_right_y();
		float get_left_trigger();
		float get_right_trigger();
//declare here so initialization works properly
		
private:
		Joystick *controller;
	
public:
		Button *const A;
		Button *const B;
		Button *const X;
		Button *const Y;
		Button *const LEFT_BUMPER;
		Button *const RIGHT_BUMPER;
		Button *const LEFT_TRIGGER;
		Button *const RIGHT_TRIGGER;
		Button *const BACK;
		Button *const START;
		Button *const LEFT_JOYSTICK_PRESS;
		Button *const RIGHT_JOYSTICK_PRESS;
		
private:
		float deadzone_value(float value, float deadzone);
		
		
};