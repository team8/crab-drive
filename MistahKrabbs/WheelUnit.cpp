#include "WheelUnit.h"

using namespace Krabbs;

WheelUnit::WheelUnit(int speedVicPort, int angleVicPort, int angleEncPort) :
  angleEnc((uint32_t)angleVicPort),
  speedVic((uint32_t)speedVicPort),
  angleVic((uint32_t)angleVicPort)
{
  targetAngle = 0;
  targetSpeed = 0;
}

WheelUnit::setSpeed(double speed) {
  targetSpeed = speed;
}

WheelUnit::setAngle(double angle) {
  targetAngle = angle;
}

double WheelUnit::getAngle() {
  //return some angle
}

WheelUnit::update() {

  speedVic(targetAngle);
  
}
