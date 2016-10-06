#pragma once

#include <WPILib.h>

class Drive_Base : public Subsystem {
public:
	Drive_Base();
	void InitDefaultCommand();
	void set_motors_normalized(float odd, float even);
private:
	CANTalon *front_left_motor,
			 *front_right_motor,
			 *back_left_motor,
			 *back_right_motor;
	float scale;
};
