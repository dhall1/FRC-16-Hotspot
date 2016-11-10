#include "drive_base.hpp"
#include "../port_mapping.hpp"
#include <WPILib.h>

Drive_Base::Drive_Base() :
Subsystem("Drive Base"),
front_left_motor  ( new CANTalon(Ports::CANBusIDs::FRONT_LEFT_MOTOR)  ),
front_right_motor ( new CANTalon(Ports::CANBusIDs::FRONT_RIGHT_MOTOR) ),
back_left_motor   ( new CANTalon(Ports::CANBusIDs::BACK_LEFT_MOTOR)   ),
back_right_motor  ( new CANTalon(Ports::CANBusIDs::BACK_RIGHT_MOTOR)  ),
scale (0.5) {
	front_left_motor->Set(0.0);
	front_right_motor->Set(0.0);
	back_left_motor->Set(0.0);
	back_right_motor->Set(0.0);
}

void Drive_Base::InitDefaultCommand() {

}

void Drive_Base::set_omni_motors_normalized(float front_right_motor, float front_left_motor, float back_right_motor, float back_left_motor) {
	Drive_Base::front_right_motor->Set(front_right_motor);
	Drive_Base::front_left_motor->Set(front_left_motor);
	Drive_Base::back_right_motor->Set(back_right_motor);
	Drive_Base::back_left_motor->Set(back_left_motor);
}

void Drive_Base::set_tank_motors_normalized(float left, float right) {
	front_left_motor->Set(left);
	back_left_motor->Set(left);
	front_right_motor->Set(right);
	back_right_motor->Set(right);
}
