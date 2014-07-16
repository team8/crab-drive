#include "HumanController.h"

using namespace Krabbs;

HumanController::HumanController(Robot *robotPointer):
	swerveStick(PORT_SWERVE),
	rotateStick(PORT_ROTATE)
{
	this->robot = robotPointer;
}

void HumanController::update() {
	if (getMagSwerveStick() >= 0.1) {
		robot->drivetrainCommand(Command::ANGLE_ALL_WHEELS, getAngSwerveStick(), getMagSwerveStick());
	} else if (abs(getRotateStick()) >= 0.1) {
		robot->drivetrainCommand(Command::ROTATE_ROBOT, getRotateStick());
	}
}
