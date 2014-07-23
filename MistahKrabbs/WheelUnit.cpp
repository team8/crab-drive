#include "WheelUnit.h"

using namespace Krabbs;

WheelUnit::WheelUnit(uint32_t angleEncPortA, uint32_t switchport, uint32_t angleEncPortB, uint32_t angleVicPort, uint32_t speedVicPort, double distancePerPulse) :
    angleEnc((uint32_t)angleEncPortA, (uint32_t)angleEncPortB),
	limitSwitch((uint32_t)switchport),
    angleVic((uint32_t)angleVicPort),
    speedVic((uint32_t)speedVicPort),
    angleController(0.1, 0.001, 0.1, &angleEnc, &angleVic)
{
	angleEnc.SetDistancePerPulse(distancePerPulse);
	angleEnc.SetPIDSourceParameter(PIDSource::kDistance);
	angleController.SetOutputRange(-1, 1);
	targetAngle = targetSpeed = currentAngle = 0;
}

void WheelUnit::init() {
	angleEnc.Start();
	calibrate();
	angleController.Enable();
}

void WheelUnit::update() {
	currentAngle = calcAngle();
	angleController.SetSetpoint(((targetAngle/360)*WHEEL_CIRCUMFERENCE)-((currentAngle/360)*WHEEL_CIRCUMFERENCE));
	angleVic.Set(angleController.Get());
	speedVic.Set(targetSpeed);
}

void WheelUnit::disable() {
	targetAngle = calcAngle();
	targetSpeed = 0.0;
	angleVic.Set(0.0);
	speedVic.Set(0.0);
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

void WheelUnit::calibrate() {
	while (true) {
		angleVic.Set(0.4);
		if (!limitSwitch.Get()) { //might have to be switched depending on electronics
			currentAngle = calcAngle();
			targetAngle = (currentAngle + SWITCH_ANGLE);
			while (targetAngle - ((2.5/360)*WHEEL_CIRCUMFERENCE) < calcAngle()  && calcAngle < targetAngle + ((5/360)*WHEEL_CIRCUMFERENCE)) {
				currentAngle = calcAngle();
				angleController.SetSetpoint(((targetAngle / 360)*WHEEL_CIRCUMFERENCE) - ((currentAngle / 360)*WHEEL_CIRCUMFERENCE));
				angleVic.Set(angleController.Get());
			}
			break;
		}
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
