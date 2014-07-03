#include "Drivetrain.h"


using namespace Krabbs;

Drivetrain::Drivetrain() : 
		Subsystem(),
		leftFront(LEFT_FRONT_ANGLE_ENC_A, LEFT_FRONT_ANGLE_ENC_B, (uint32_t)LEFT_FRONT_ANGLE_VIC, (uint32_t)LEFT_FRONT_SPEED_VIC, /*SOMETHING*/),
		leftBack(),
		rightFront(),
		rightBack()

{
	
}

Drivetrain::~Drivetrain() {
	
}

void Drivetrain::init() {
	
}

void Drivetrain::update() {
	switch (state) {
	case IDLE:
		break;
	case TELE_DRIVING:
		break;
	}
}

void Drivetrain::disable() {
	
}

void Drivetrain::runCommand(Command::DriveCommand command, double arg) {
	switch (command) {
	case (Command::ANGLE_ALL_WHEELS):
			break;
	case (Command::MOVE_ALL_WHEELS):
			break;
	case (Command::ANGLE_FRONT_WHEELS):
			break;
	case (Command::ANGLE_BACK_WHEELS):
			break;
	}
}
