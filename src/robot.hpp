#pragma once

#include <WPILib.h>

class Robot : public IterativeRobot {
private:
	void RobotInit();
	void TeleopInit() {};
	void TeleopPeriodic();
};
