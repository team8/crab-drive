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
			IDLE
		} state;
		
		void setAngle(double ang);
		void setFrontAngle(double ang);
		void setBackAngle(double ang);
		void setSpeed(double spd);
		
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
