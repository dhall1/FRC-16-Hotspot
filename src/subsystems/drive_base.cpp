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

void Drive_Base::set_motors_normalized(float odd, float even) {
	front_left_motor->Set(even);
	front_right_motor->Set(odd);
	back_left_motor->Set(odd);
	back_right_motor->Set(even);
}
