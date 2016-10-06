#include "subsystems/subsystems.hpp"
#include "user_interface.hpp"
#include "robot.hpp"
#include <WPILib.h>

void Robot::RobotInit() {
	Subsystems::Initialize();
	UI::Initialize();
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot)
