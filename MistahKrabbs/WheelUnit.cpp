#include "WheelUnit.h"

using namespace Krabbs;

WheelUnit::WheelUnit(uint32_t angleEncPortA, uint32_t angleEncPortB, uint32_t angleVicPort, uint32_t speedVicPort, double distancePerPulse) :
    angleEnc((uint32_t)angleEncPortA, (uint32_t)angleEncPortB),
    angleVic((uint32_t)angleVicPort),
    speedVic((uint32_t)speedVicPort),
    angleController(0.1, 0.001, 0.1, &angleEnc, &angleVic)
{
	angleEnc.SetDistancePerPulse(distancePerPulse);
	angleEnc.SetPIDSourceParameter(Encoder::PIDSourceParameter::kDistance);
	angleController.SetOutputRange(-1, 1);
	targetAngle = targetSpeed = currentAngle = 0;
}

void WheelUnit::init() {
	angleEnc.Start();
	angleController.Enable();
}

void WheelUnit::update() {
	currentAngle = calcAngle();
	angleController.SetSetpoint(((targetAngle/360)*WHEEL_CIRCUMFERENCE)-((currentAngle/360)*WHEEL_CIRCUMFERENCE));
	angleVic.SetSpeed(angleController.Get());
	speedVic.SetSpeed(targetSpeed);
}

void WheelUnit::disable() {
	targetAngle = calcAngle();
	targetSpeed = 0.0;
	angleVic.SetSpeed(0.0);
	speedVic.SetSpeed(0.0);
	angleController.Disable();
}

double WheelUnit::calcAngle() { //should return -180 to 180
	double dist = angleEnc.GetDistance();
	if (dist == 0) {
		return 0;
	} else if (dist > 0) {
		if (dist > WHEEL_CIRCUMFERENCE) {
			dist = modulo(WHEEL_CIRCUMFERENCE, dist);
		}
		return (((dist/WHEEL_CIRCUMFERENCE)*360)-180);
	} else if (dist < 0) {
		if (dist < -WHEEL_CIRCUMFERENCE) {
			dist = modulo(-WHEEL_CIRCUMFERENCE, dist);		
		}
		if (dist == 0) {
			return 0;
		}
		return (((dist/WHEEL_CIRCUMFERENCE)*360)-180);
	}
}

void WheelUnit::setAngle(double ang) { 
	targetAngle = ang;
}

void WheelUnit::setSpeed(double spd) {
	targetSpeed = spd;
}

double modulo(double a, double b) {
	double original = a;
	while (b <= a) {
		a += original;
	}
	a -= original;
	return (b - a);
}
