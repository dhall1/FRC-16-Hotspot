#include <robot.hpp>
#include <subsystems/subsystems.hpp>

Drive_Base *Subsystems::drive_base = 0;

void Subsystems::Initialize() {
	drive_base = new Drive_Base();
}
