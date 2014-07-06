#ifndef ROBOT_H
#define ROBOT_H
#include <WPILib.h>

#include "Drivetrain.h"

namespace Krabbs {

	class Robot {
		
		private: 
			Drivetrain *drivetrain;
		public:
			Robot();
			
			void drivetrainCommand(Command::DriveCommand command, double arg, double arg2 = 0);
			
			void update();
			void init();
			void disable();
	
	};

}
#endif
