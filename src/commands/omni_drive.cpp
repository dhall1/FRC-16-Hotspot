#include "omni_drive.hpp"
#include "../user_interface.hpp"
#include "../subsystems/subsystems.hpp"
#include "../xbox_controller.hpp"

#include <WPILib.h>
#include <cmath>

Omni_Drive::Omni_Drive() {
	Requires(Subsystems::drive_base);
}

void Omni_Drive::Execute() {
	//Turn
	float right_stick_y = UI::controller->get_right_y();
	float right_stick_x = UI::controller->get_right_x();

	//Strafe
	float left_stick_y = UI::controller->get_left_y();
	float left_stick_x = UI::controller->get_left_x();

	float angle;

	if (left_stick_y>0 && left_stick_x>0){
		angle = atan(left_stick_y/left_stick_x);

	}else if (left_stick_y>0 && left_stick_x<0){
		angle = atan(left_stick_y/left_stick_x)+180;

	} else if (left_stick_y<0 && left_stick_x<0){
		angle = atan(left_stick_y/left_stick_x)+180;

	} else if (left_stick_y<0 && left_stick_x>0){
		angle = atan(left_stick_y/left_stick_x);
	}

	float magnitude = sqrt(pow(left_stick_y, 2)+ pow(left_stick_x, 2));
	float odd_power =  magnitude*sin(angle);
	float even_power = magnitude*cos(angle);

	//Exponential scaling
	float scaled_odd_power = (2*pow(108, odd_power))-1;
	float scaled_even_power = (2*pow(108, even_power))-1;


	Subsystems::drive_base->set_motors_normalized(scaled_odd_power, scaled_even_power);

}

void Omni_Drive::End() {

}

bool Omni_Drive::IsFinished() {
	return true;
}


