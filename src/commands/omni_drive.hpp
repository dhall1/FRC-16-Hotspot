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
};
