#ifndef WHEEL_UNIT_H
#define WHEEL_UNIT_H
#include <WPILib.h>

namespace Krabbs {

class WheelUnit {
  private:
    Victor speedVic;
    Victor angleVic;
    Encoder angleEnc;
    double targetAngle;
    double targetSpeed;
    
  public:
    WheelUnit(int speedVicPort, int angleVicPort, int angleEncPort);
    //set speed of speedVic
    setSpeed(double speed);
    //set angle of wheel
    setAngle(double angle);
    //get angle
    double getAngle();
    
    update();

};

}
#endif
