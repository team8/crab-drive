#ifndef WHEEL_UNIT_H
#define WHEEL_UNIT_H
#include <WPILib.h>
#include "Constants.h"

namespace Krabbs {

	class WheelUnit {
	  private:
		Encoder angleEnc;
		Victor speedVic;
		Victor angleVic;
		PIDController angleController;
		double targetAngle;
		double targetSpeed;
		double currentAngle;
		
		double calcAngle();
		double modulo(double a, double b);
		
	  public:
		WheelUnit(uint32_t angleEncPortA, uint32_t angleEncPortB, uint32_t angleVicPort, uint32_t speedVicPort, double distancePerPulse);
		
		void init();
		void update();
		void disable();
		
		void setAngle(double ang);
		void setSpeed(double spd);
		
		double getAngle();
	
	};

}
#endif
