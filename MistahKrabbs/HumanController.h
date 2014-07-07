#ifndef HUMANCONTROLLER_H
#define HUMANCONTROLLER_H
#include "Constants.h"
#include "Robot.h"
#include <WPILib.h>
#include <cmath>

namespace Krabbs {

	class HumanController {
	private:
		Robot *robot;
		Joystick swerveStick;
		Joystick rotateStick; 
		
		double getRotateStick() const { return rotateStick.GetX(); }
		double getAngSwerveStick() const { return swerveStick.GetDirectionDegrees(); }
		double getMagSwerveStick() const { return swerveStick.GetMagnitude(); }
	public:
		HumanController(Robot *robot);
		void update();
	};

}
#endif
