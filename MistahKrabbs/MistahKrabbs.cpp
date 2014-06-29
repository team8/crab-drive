#include "Constants.h"
#include "Robot.h"
#include "HumanController.h"
#include <iostream>

namespace Krabbs {

	class MistahKrabbs : public IterativeRobot {
	private:
		Robot robot;
		HumanController humanCtrlr;
	public:
		MistahKrabbs();
		virtual ~MistahKrabbs();
		
		void RobotInit();
		void DisabledInit();
		void DisabledPeriodic();
		void TeleopInit();
		void TeleopPeriodic();
		void TeleopDisabled();
	};
	
}

using namespace Krabbs;

MistahKrabbs::MistahKrabbs():
robot(),
humanCtrlr(&robot)
{
	std::cout << "MistahKrabbs constructor" << std::endl;
}


void MistahKrabbs::RobotInit() {
	std::cout << "robot init" << std::endl;
}

void MistahKrabbs::DisabledInit() {
	robot.disable();
	std::cout << "robot disable" << std::endl;
}

void MistahKrabbs::DisabledPeriodic() {
	robot.disable();
	robot.update();
}

void MistahKrabbs::TeleopInit() {
	std::cout << "Teleop init" << std::endl;
	robot.init();
}

void MistahKrabbs::TeleopPeriodic() {
	humanCtrlr.update();
	robot.update();
}

void MistahKrabbs::TeleopDisabled() {
	robot.disable();
	robot.update();
}

START_ROBOT_CLASS(Krabbs::MistahKrabbs);
