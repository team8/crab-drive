#include "Robot.h"

using namespace Krabbs;

Robot::Robot() {
  drivetrain = new Drivetrain();
}

Robot::update() {
  drivetrain->update();
}

Robot::drivetrainCommand(DriveCommand command, double arg) {
  drivetrain->runCommand(command, arg);
}

