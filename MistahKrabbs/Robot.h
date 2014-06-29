#ifndef ROBOT_H
#define ROBOT_H
#include <WPILib.h>

namespace Krabbs {
	class Robot;
}


#include "Drivetrain.h"

namespace Krabbs {

	class Robot {
		
		private: 
			Drivetrain *drivetrain;
		public:
			Robot();
			
			typedef enum DriveCommand {
				ANGLE_ALL_WHEELS,
				MOVE_ALL_WHEELS,
				ANGLE_FRONT_WHEELS,
				ANGLE_BACK_WHEELS
			} DriveCommand;
			
			void drivetrainCommand(DriveCommand command, double arg);
			
			void update();
	
	};

}
#endif
