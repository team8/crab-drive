#include "Robot.h"

using namespace Krabbs;

Robot::Robot() {
  drivetrain = new Drivetrain();
}

void Robot::update() {
  drivetrain->update();
}

void Robot::drivetrainCommand(Command::DriveCommand command, double arg, double arg2) {
  drivetrain->runCommand(command, arg, arg2);
}

void Robot::init() {
	drivetrain->init();
}

void Robot::disable() {
	drivetrain->disable();
}
