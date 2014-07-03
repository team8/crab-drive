#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "Subsystem.h"
#include "WheelUnit.h"

namespace Krabbs {

	class Drivetrain : public Subsystem {
		
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
		
		virtual void runCommand(Command::DriveCommand command, double arg);
	} ;

}

#endif
