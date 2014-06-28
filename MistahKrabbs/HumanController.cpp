#include "HumanController.h"
#include <stdlib.h>
#include <cmath>

using namespace Krabbs;

HumanController::HumanController(Robot* robotPointer):
	moveStick(PORT_MOVE_STICK),
	turnStick(PORT_TURN_STICK)
{
	this->robot = robotPointer;
}

void HumanController::update() {
	robot->drivetrainCommand(Robot::DrivetrainCommand.ANGLE_FRONT_WHEELS, getAngMoveStick() + getAbsTurnStick())
	robot->drivetrainCommand(Robot::DrivetrainCommand.ANGLE_BACK_WHEELS , getAngMoveStick() - getAbsTurnStick())
	
	robot->drivetrainCommand(Robot::DrivetrainCommand.MOVE_ALL_WHEELS, getMagMoveStick())
}

double HumanController::getAngMoveStick() {
	return atan2(moveStick.getY(), moveStick.getX())
}

double HumanController::getMagMoveStick() {
	return sqrt(pow(moveStick.getX(), 2.0) + pow(moveStick.getY(), 2.0))/sqrt(2.0)
}

double HumanController::getAbsTurnStick() {
	return abs(turnStick().getX())
}
