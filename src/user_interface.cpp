#include "user_interface.hpp"
#include "commands/change_drive.hpp"

#include <WPILib.h>

Xbox_Controller *UI::controller = 0;
bool UI::drive_toggle = false;

void UI::Initialize() {
	controller = new Xbox_Controller(0);
}
