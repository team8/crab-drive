#include "Robot.h"

Robot::Robot() {
  drivetrain();
}

Robot::update() {
  drivetrain.update();
}

Robot::drivetrainCommand(DriveCommand command, DriveArgs arg) {
  drivetrain.runCommand(command, arg);
}
