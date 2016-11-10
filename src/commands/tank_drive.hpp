#pragma once

#include <WPILib.h>

class Tank_Drive : public Command {
public:
	Tank_Drive();
	void Initialize() {};
	void Execute();
	void End();
	bool IsFinished();
	void Interrupted();

	float left_stick_y = 0;
	float right_stick_y = 0;
};
