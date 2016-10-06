#include "xbox_controller.hpp"

#include <WPILib.h>

Xbox_Controller::Xbox_Controller(uint32_t port) :
controller( new Joystick(port) ),
A( new JoystickButton(controller, 1) ),
B( new JoystickButton(controller, 2) ),
X( new JoystickButton(controller, 3) ),
Y( new JoystickButton(controller, 4) ),
LEFT_BUMPER( new JoystickButton(controller, 5) ),
RIGHT_BUMPER( new JoystickButton(controller, 6) ),
BACK( new JoystickButton(controller, 7) ),
START( new JoystickButton(controller, 8) ),
LEFT_JOYSTICK_PRESS( new JoystickButton(controller, 9) ),
RIGHT_JOYSTICK_PRESS( new JoystickButton(controller, 10) ),
LEFT_TRIGGER( new JoystickButton(controller, 11) ),
RIGHT_TRIGGER( new JoystickButton(controller, 12) ) {
}

float Xbox_Controller::get_left_x() {
	return deadzone_value(controller->GetRawAxis(0), 0.3);
}
float Xbox_Controller::get_left_y() {
	return deadzone_value(controller->GetRawAxis(1), 0.3);
}

float Xbox_Controller::get_right_x() {
	return deadzone_value(controller->GetRawAxis(4), 0.3);
}

float Xbox_Controller::get_right_y() {
	return deadzone_value(controller->GetRawAxis(5), 0.3);
}

float Xbox_Controller::get_left_trigger() {
	return deadzone_value(controller->GetRawAxis(2), 0.3);
}

float Xbox_Controller::get_right_trigger() {
	return deadzone_value(controller->GetRawAxis(3), 0.3);
}

float Xbox_Controller::deadzone_value(float value, float deadzone) {
	if (value < deadzone){
		return 0;
	} else {
		return value;
	}
}
