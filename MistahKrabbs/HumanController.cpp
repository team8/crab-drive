#include "HumanController.h"

using namespace Krabbs;

HumanController::HumanController(Robot *robotPointer):
	swerveStick(PORT_SWERVE),
	rotateStick(PORT_ROTATE)
{
	this->robot = robotPointer;
}

void HumanController::update() {
	if (swerveStick.GetX() != 0.0 || swerveStick.GetY() != 0.0) {
		robot->drivetrainCommand(Command::ANGLE_ALL_WHEELS, getAngSwerveStick(), getMagSwerveStick());
	} else if (getRotateStick() != 0.0) {
		robot->drivetrainCommand(Command::ROTATE_ROBOT, getRotateStick());
	}
}