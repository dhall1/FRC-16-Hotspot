#include "user_interface.hpp"
#include "./commands/change_drive.hpp"

#include <WPILib.h>

Xbox_Controller *UI::controller = 0;

void UI::Initialize() {
	UI::controller = new Xbox_Controller(1);
	//UI::controller->RIGHT_BUMPER->WhenPressed( new Cambiar_Drive() );
}
