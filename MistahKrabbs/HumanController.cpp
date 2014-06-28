#include "HumanController.h"
#include <stdlib.h>
#include <cmath>

HumanController::HumanController(Robot* robotPointer):
	moveStick(PORT_MOVE_STICK),
	turnStick(PORT_TURN_STICK)
{
	this->robot = robotPointer;
}

void HumanController::update() {
	//send command: angle wheels to getAngMoveStick()
	//send command: set wheel speed to getMagMoveStick()
}

double HumanController::getAngMoveStick() {
	return atan2(moveStick.getY(), moveStick.getX())
}

double HumanController::getMagMoveStick() {
	return sqrt(pow(moveStick.getX(), 2.0) + pow(moveStick.getY(), 2.0))
}

double HumanController::getAbsTurnStick() {
	return abs(turnStick().getX())
}
