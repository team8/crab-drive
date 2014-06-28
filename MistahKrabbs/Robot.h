#ifndef ROBOT_H
#define ROBOT_H
#include <WPILib.h>

class Robot {
	
	private: 
		Drivetrain drivetrain;
	
	public:
		Robot();
		void drivetrainCommand(DriveCommand command, DriveArgs arg);
		void update();
		
		typedef enum DriveCommand {
			ANGLE_ALL_WHEELS,
			MOVE_ALL_WHEELS,
			ANGLE_FRONT_WHEELS,
			ANGLE_BACK_WHEELS
		} DriveCommand;
		
		typedef union DriveArgs {
			double allWheelAngle;
			double allWheelSpeed;
			double frontWheelAngle;
			double backWheelAngle;
		} DriveArgs;

};

#endif
