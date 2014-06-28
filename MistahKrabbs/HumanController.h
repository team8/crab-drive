#ifndef HUMANCONTROLLER_H
#define HUMANCONTROLLER_H
#include "Constants.h"
#include "Robot.h"

class HumanController {
public:
	void update();
	HumanController(Robot* robot)
	
private:
	Robot* robot;
	Joystick moveStick;
	Joystick turnStick;
	
	double getAbsMoveStick();
	double getAbsTurnStick();
}
#endif
