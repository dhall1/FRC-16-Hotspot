#pragma once

#include <WPILib.h>

class Omni_Drive : public Command {
public:
	Omni_Drive();
	void Initialize() {};
	void Execute();
	void End();
	bool IsFinished();
	void Interrupted() {};

	float left_stick_x = 0;
	float left_stick_y = 0;
	float right_stick_x = 0;
	float right_stick_y = 0;
};
