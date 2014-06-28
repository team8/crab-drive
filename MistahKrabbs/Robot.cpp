#include "Robot.h"

Robot::Robot() {
  drivetrain();
}

Robot::update() {
  drivetrain.update();
}
