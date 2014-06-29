#include "WheelUnit.h"

using namespace Krabbs;

WheelUnit::WheelUnit(int speedVicPort, int angleVicPort, int angleEncPortA, int angleEncPortB, bool direction, double distancePerPulse) :
  angleEnc((uint32_t)angleEncPortA,(uint32_t)angleEncPortB, direction),
  speedVic((uint32_t)speedVicPort),
  angleVic((uint32_t)angleVicPort),
  angleController(0.1, 0.001, 0.1, &angleEnc, &angleVic)
{
	angleController.SetOutputRange(-1,1);
	angleEnc.SetDistancePerPulse(distancePerPulse);
	angleEnc.SetPIDSourceParameter(PIDSourceParameter::kDistance);
	angleController.Enable();
	currentAngle = 0;
	targetAngle = 0;
	targetSpeed = 0;
}
void WheelUnit::init(double setDistancePerPulse) {
	
}

void WheelUnit::setSpeed(double speed) {
	targetSpeed = speed;
}

void WheelUnit::setAngle(double angle) {
	targetAngle = angle;
}

double WheelUnit::calcAngle() {
	double angle = 0;
	if(angleEnc.GetDistance() < 0) {
		if(angleEnc>=-1) {
			angleEnc = angleEnc-(int)angleEnc;
		}
		angle = 360+(angleEnc.GetDistance()*360);
	}
	if(angleEnc.getDistance()>0) {
		angle = (angleEnc.GetDistance()*360);
	}
	if(angle >= 360) {
		angle = angle%360;
	}
	return angle;
}

void WheelUnit::update() {
	
	angleController.SetSetpoint(do later);
	speedVic(targetSpeed);
}
