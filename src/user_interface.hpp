#pragma once 

#include "xbox_controller.hpp"

#include <WPILib.h>

namespace UI {
	extern Xbox_Controller *controller;
	bool drive_toggle = false; //If false, omnidrive, if true, tank drive
	void Initialize();
}
