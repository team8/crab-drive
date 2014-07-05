#include "HumanController.h"
#include <stdlib.h>
#include <cmath>

using namespace Krabbs;

HumanController::HumanController(Robot *robotPointer):
	moveStick(PORT_STRAFE),
	turnStick(PORT_ROTATE)
{
	this->robot = robotPointer;
}

void HumanController::update() {
	robot->drivetrainCommand(Command::ANGLE_FRONT_WHEELS, getAngMoveStick() + getAbsTurnStick());
	robot->drivetrainCommand(Command::ANGLE_BACK_WHEELS , getAngMoveStick() - getAbsTurnStick());
	
	robot->drivetrainCommand(Command::MOVE_ALL_WHEELS, getMagMoveStick());
}

double HumanController::getAngMoveStick() {
	return atan2(moveStick.GetY(), moveStick.GetX());
}

double HumanController::getMagMoveStick() {
	return sqrt(pow(moveStick.GetX(), 2.0) + pow(moveStick.GetY(), 2.0))/sqrt(2.0);
}

double HumanController::getAbsTurnStick() {
	return abs(turnStick.GetX());
}
