#ifndef WHEEL_UNIT_H
#define WHEEL_UNIT_H
#include <WPILib.h>

namespace Krabbs {

class WheelUnit {
  private:
    Victor speedVic;
    Victor angleVic;
    Encoder angleEnc;
    PIDController angleController;
    double targetAngle;
    double targetSpeed;
    double currentAngle;
    double calcAngle();
    
  public:
    WheelUnit(int speedVicPort, int angleVicPort, int angleEncPortA, int angleEncPortB, bool direction, double distancePerPulse);
    //set speed of speedVic
    void setSpeed(double speed);
    //set angle of wheel
    void setAngle(double angle);
    //get angle

    
    void update();

};

}
#endif
