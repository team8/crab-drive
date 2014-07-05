#ifndef WHEEL_UNIT_H
#define WHEEL_UNIT_H
#include <WPILib.h>
#include "Constants.h"

namespace Krabbs {

	class WheelUnit {
	  private:
		Encoder angleEnc;
		Victor angleVic;
		Victor speedVic;
		PIDController angleController;
		double targetAngle;
		double targetSpeed;
		double currentAngle;
		
		double calcAngle();
		
	  public:
		WheelUnit(uint32_t angleEncPortA, uint32_t angleEncPortB, uint32_t angleVicPort, uint32_t speedVicPort, double distancePerPulse);
		
		void init();
		void update();
		void disable();
		
		void setAngle(double ang); //Expects an ANGLE not a distance. -360 to 360
		void setSpeed(double spd); // -1 to 1
		
		double getCurrentAngle() {
			return currentAngle;
		}
		double getTargetAngle() {
			return targetAngle;
		}
	
	};
	double modulo(double a, double b);
}
#endif
