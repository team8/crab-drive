#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "Subsystem.h"
#include "WheelUnit.h"

//gyroscope
namespace Krabbs {

	class Drivetrain : public Subsystem {
		
	private:
		WheelUnit leftFront, leftBack, rightFront, rightBack;		
		Gyro gyro;
		
		double currentAngle;
		double targetAngle;
		
		enum State {
			TELE_DRIVING = 12043,
			ROTATING = 9072,
			IDLE = 72003
		} state;
		
		void setAngle(double ang);
		void setSpeed(double spd);
		void rotate(double spd);
		
	public:
		Drivetrain();
		virtual ~Drivetrain();
		
		virtual void init();
		virtual void update();
		virtual void disable();
		
		virtual void runCommand(Command::DriveCommand command, double arg, double arg2); // when MOVE_ALL_WHEELS, arg is speed. when any other DriveCommand, arg is angle and arg2 is speed 
	};

}

#endif
