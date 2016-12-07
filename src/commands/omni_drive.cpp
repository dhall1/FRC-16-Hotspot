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
	float right_stick_x = 0;//UI::controller->get_right_x();

	//Strafe
	float left_stick_y = 0;//UI::controller->get_left_y();
	float left_stick_x = 0;//UI::controller->get_left_x();

	//ADD DEADZONE

	if ((left_stick_y == 0) && (left_stick_x == 0) && (right_stick_x == 0)) {
		Subsystems::drive_base->set_omni_motors_normalized(0, 0, 0, 0);
		return;
	}

	float strafe_angle = 0;

	if (left_stick_x>0){
		strafe_angle = atan(left_stick_y/left_stick_x);
	} else if (left_stick_x<0){
		strafe_angle = atan(left_stick_y/left_stick_x) + 180;
	} else if (left_stick_y>0){
		strafe_angle = 0;
	} else if (left_stick_y<0){
		strafe_angle = 180;
	}

	float power_angle = strafe_angle + 45;



	float magnitude = sqrt(pow(left_stick_y, 2)+ pow(left_stick_x, 2))/1;
	float odd_power =  magnitude*sin(power_angle);
	float even_power = magnitude*cos(power_angle);

	//Exponential scaling
	float set_1_power = (2*pow(108, odd_power))-1;
	float set_2_power = (2*pow(108, even_power))-1;


	float velocity_front_right = set_1_power + right_stick_x;
	float velocity_front_left = set_2_power + right_stick_x;
	float velocity_back_right = set_1_power - right_stick_x;
	float velocity_back_left = set_2_power - right_stick_x;

	Subsystems::drive_base->set_omni_motors_normalized(velocity_front_right, velocity_front_left, velocity_back_right, velocity_back_left);

}

void Omni_Drive::End() {

}

bool Omni_Drive::IsFinished() {
//	return UI::drive_toggle;
	return false;
}

void Omni_Drive::Interrupted() {
	Subsystems::drive_base->set_omni_motors_normalized(0, 0, 0, 0);
}
