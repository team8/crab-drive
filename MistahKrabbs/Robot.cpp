#include "Robot.h"

using namespace Krabbs;

Robot::Robot() {
  drivetrain = new Drivetrain();
}

void Robot::update() {
  drivetrain->update();
}

void Robot::drivetrainCommand(Command::DriveCommand command, double arg) {
  drivetrain->runCommand(command, arg);
}

void Robot::init() {
	
}

void Robot::disable() {
	
}
