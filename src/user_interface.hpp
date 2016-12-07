#pragma once 

#include "xbox_controller.hpp"

#include <WPILib.h>

namespace UI {
	extern Xbox_Controller *controller;
	extern bool drive_toggle;
	void Initialize();
}
