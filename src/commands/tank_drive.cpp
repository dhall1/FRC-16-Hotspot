#include "tank_drive.hpp"
#include "../user_interface.hpp"
#include "../subsystems/subsystems.hpp"
#include "../xbox_controller.hpp"

float scale_input(float input) {
	return input * fabs(input) * 0.8;
}

Tank_Drive::Tank_Drive() {
	Requires(Subsystems::drive_base);
}

void Tank_Drive::Execute() {
	//Left side
	left_stick_y = UI::controller->get_left_y();
	//Right side
	right_stick_y = UI::controller->get_right_y();

	Subsystems::drive_base->set_tank_motors_normalized (
		scale_input(left_stick_y),
		scale_input(right_stick_y)
	);

}

void Tank_Drive::End() {

}

bool Tank_Drive::IsFinished() {
	return !UI::drive_toggle;
}

void Tank_Drive::Interrupted() {
	Subsystems::drive_base->set_tank_motors_normalized(0, 0);
}
