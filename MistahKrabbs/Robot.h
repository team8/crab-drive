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
			
			void drivetrainCommand(Command::DriveCommand command, double arg);
			
			void update();
			void init();
			void disable();
	
	};

}
#endif
