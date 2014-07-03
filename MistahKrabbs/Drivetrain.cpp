#include "Drivetrain.h"


using namespace Krabbs;

Drivetrain::Drivetrain() : 
		Subsystem(),
		leftFront((uint32_t)LEFT_FRONT_ANGLE_ENC_A, (uint32_t)LEFT_FRONT_ANGLE_ENC_B, (uint32_t)LEFT_FRONT_ANGLE_VIC, (uint32_t)LEFT_FRONT_SPEED_VIC, WHEEL_DIST_PER_PULSE),
		leftBack((uint32_t)LEFT_BACK_ANGLE_ENC_A, (uint32_t)LEFT_BACK_ANGLE_ENC_B, (uint32_t)LEFT_BACK_ANGLE_VIC, (uint32_t)LEFT_BACK_SPEED_VIC, WHEEL_DIST_PER_PULSE),
		rightFront((uint32_t)RIGHT_FRONT_ANGLE_ENC_A, (uint32_t)RIGHT_FRONT_ANGLE_ENC_B, (uint32_t)RIGHT_FRONT_ANGLE_VIC, (uint32_t)RIGHT_FRONT_SPEED_VIC, WHEEL_DIST_PER_PULSE),
		rightBack((uint32_t)RIGHT_BACK_ANGLE_ENC_A, (uint32_t)RIGHT_BACK_ANGLE_ENC_B, (uint32_t)RIGHT_BACK_ANGLE_VIC, (uint32_t)RIGHT_BACK_SPEED_VIC, WHEEL_DIST_PER_PULSE)
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
