#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WheelUnit.h"

class Drivetrain : public Subsystem {
private:
	WheelUnit leftFront, leftBack, rightFront, rightBack;
	
	enum State {
		TELE_DRIVING = 12043,
		IDLE
	};
	
public:
	Drivetrain();
	~Drivetrain();
	
	void update();
	
};

#endif
