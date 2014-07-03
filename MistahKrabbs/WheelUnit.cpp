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
	angleController.Enable();
	targetAngle = targetSpeed = currentAngle = 0;
}

void WheelUnit::init() {
	angleEnc.Start();
}

void WheelUnit::update() {
	currentAngle = calcAngle();
	angleController.SetSetpoint(targetAngle-currentAngle);
	angleVic.SetSpeed(angleController.Get());
	
}

void WheelUnit::disable() {
	angleVic.SetSpeed(0);
	speedVic.SetSpeed(0);
	angleController.Disable();
}

double WheelUnit::calcAngle() {
	double dist = angleEnc.GetDistance();
	if (dist == 0) {
		return 0;
	} else if (dist > 0) {
		if (dist > WHEEL_CIRCUMFERENCE) {
			dist = modulo(WHEEL_CIRCUMFERENCE, dist);
		}
		if (dist == 0) {
			return 0;
		}
		return ((dist/WHEEL_CIRCUMFERENCE)*360);
	} else if (dist < 0) {
		if (dist < -WHEEL_CIRCUMFERENCE) {
			dist = modulo(-WHEEL_CIRCUMFERENCE, dist);		
		}
		if (dist == 0) {
			return 0;
		}
		return ((dist/-WHEEL_CIRCUMFERENCE)*360);
	}
	
}

void WheelUnit::setAngle(double ang) { 
	targetAngle = ang;
}

void WheelUnit::setSpeed(double spd) {
	targetSpeed = spd;
}

double WheelUnit::modulo(double a, double b) {
	double original = a;
	while (b <= a) {
		a += original;
	}
	a -= original;
	return (b - a);
}

double WheelUnit::getAngle() {
	return currentAngle;
}
