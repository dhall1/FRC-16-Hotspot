#include "change_drive.hpp"
#include "omni_drive.hpp"
#include "tank_drive.hpp"
#include "../user_interface.hpp"

Change_Drive::Change_Drive() {
	UI::drive_toggle = !UI::drive_toggle;
	if(UI::drive_toggle) {
		AddSequential( new Tank_Drive() );
	} else {
		AddSequential( new Omni_Drive() );
	}
}
