#ifndef HUMANCONTROLLER_H
#define HUMANCONTROLLER_H
#include "Constants.h"
#include "Robot.h"
#include <WPILib.h>

namespace Krabbs {

	class HumanController {
	private:
		Robot *robot;
		Joystick moveStick;
		Joystick turnStick;
		
		double getMagMoveStick();
		double getAngMoveStick();
		
		double getAbsTurnStick();
	public:
		HumanController(Robot *robot);
		void update();
	};

}
#endif
