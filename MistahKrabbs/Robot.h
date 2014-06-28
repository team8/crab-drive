#ifndef ROBOT_H
#def ROBOT_H
#include <WPILib.h>

class Robot {
	
	private: 
		Drivetrain drivetrain;
	
	public:
		Robot();
		void update();
		typedef enum DriveCommands {
			ANGLE_ALL_WHEELS,
			MOVE_ALL_WHEELS,
			ANGLE_FRONT_WHEELS,
			ANGLE_BACK_WHEELS-
		}
		typedef union DriveArgs {
			double allWheelAngle,
			double allWheelSpeed,
			double frontWheelAngle,
			double backWheelAngle
		}

}
#endif
