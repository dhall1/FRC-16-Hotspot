#pragma once

#include <WPILib.h>

class Drive_Base : public Subsystem {
public:
	Drive_Base();
	void InitDefaultCommand();
	void set_omni_motors_normalized(float front_right_motor, float front_left_motor, float back_right_motor, float back_left_motor);
	void set_tank_motors_normalized(float left, float right);
private:
	Talon *front_left_motor,
			 *front_right_motor,
			 *back_left_motor,
			 *back_right_motor;
	float scale;
};
