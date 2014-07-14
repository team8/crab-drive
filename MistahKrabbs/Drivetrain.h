#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "Subsystem.h"
#include "WheelUnit.h"

//gyroscope
namespace Krabbs {

	class Drivetrain : public Subsystem {
		
	private:
		WheelUnit leftFront, leftBack, rightFront, rightBack;		
		Gyro gyro; //currently unused
		
		double currentAngle; //unused
		double targetAngle; //unused
		
		enum {
			TELE_DRIVING,
			ROTATING,
			IDLE
		} state;
	
		enum {
			LR, FB
		} parallels;

		int invert;

		void setAngle(double ang);
		void setSpeed(double spd);
		void rotate(double spd);
		void updateQuadrant();
		
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
