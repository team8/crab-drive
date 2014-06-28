#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "WheelUnit.h"
#include "Subsystem.h"

class Drivetrain : public Subsyst {
	
private:
	WheelUnit leftFront, leftBack, rightFront, rightBack;
	
	enum State {
		TELE_DRIVING = 12043,
		IDLE
	} state;
	
public:
	Drivetrain();
	virtual ~Drivetrain();
	
	virtual void init();
	virtual void update();
	virtual void disable();
};

#endif
