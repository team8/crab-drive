#include "Drivetrain.h"

using namespace Krabbs;

Drivetrain::Drivetrain() : 
		Subsystem(),
		leftFront((uint32_t)LEFT_FRONT_ANGLE_ENC_A, (uint32_t)LEFT_FRONT_ANGLE_ENC_B, (uint32_t)LEFT_FRONT_ANGLE_VIC, (uint32_t)LEFT_FRONT_SPEED_VIC, WHEEL_DIST_PER_PULSE),
		leftBack((uint32_t)LEFT_BACK_ANGLE_ENC_A, (uint32_t)LEFT_BACK_ANGLE_ENC_B, (uint32_t)LEFT_BACK_ANGLE_VIC, (uint32_t)LEFT_BACK_SPEED_VIC, WHEEL_DIST_PER_PULSE),
		rightFront((uint32_t)RIGHT_FRONT_ANGLE_ENC_A, (uint32_t)RIGHT_FRONT_ANGLE_ENC_B, (uint32_t)RIGHT_FRONT_ANGLE_VIC, (uint32_t)RIGHT_FRONT_SPEED_VIC, WHEEL_DIST_PER_PULSE),
		rightBack((uint32_t)RIGHT_BACK_ANGLE_ENC_A, (uint32_t)RIGHT_BACK_ANGLE_ENC_B, (uint32_t)RIGHT_BACK_ANGLE_VIC, (uint32_t)RIGHT_BACK_SPEED_VIC, WHEEL_DIST_PER_PULSE),
		gyro((uint32_t)GYRO_PORT),
		currentAngle(0),
		targetAngle(0)
{

}

Drivetrain::~Drivetrain() {
	
}

void Drivetrain::init() {
	leftFront.init();
	leftBack.init();
	rightFront.init();
	rightBack.init();
	gyro.Reset();
	currentAngle = targetAngle = (gyro.GetAngle() >=360) ? modulo(360, gyro.GetAngle()) : gyro.GetAngle();
}

void Drivetrain::update() {
	switch (state) {
	case IDLE:
		leftFront.disable();
		leftBack.disable();
		rightFront.disable();
		rightBack.disable();
		leftFront.update();
		leftBack.update();
		rightFront.update();
		rightBack.update();
		break;
	case TELE_DRIVING:
		currentAngle = (gyro.GetAngle() >=360) ? modulo(360, gyro.GetAngle()) : gyro.GetAngle();
		if (abs(targetAngle - currentAngle) <= 5.0) {
			targetAngle = currentAngle;
		} else {
			setAngle(targetAngle);
		}
		leftFront.update();
		leftBack.update();
		rightFront.update();
		rightBack.update();
		break;
	case ROTATING:
		leftFront.update();
		leftBack.update();
		rightFront.update();
		rightBack.update();
		break;
	}
}

void Drivetrain::disable() {
	leftFront.disable();
	leftBack.disable();
	rightFront.disable();
	rightBack.disable();
	state = IDLE;
}

void Drivetrain::setAngle(double ang) {
	targetAngle = ang;
	leftFront.setAngle(targetAngle);
	rightFront.setAngle(targetAngle);
	leftBack.setAngle(targetAngle);
	rightBack.setAngle(targetAngle);
	state = TELE_DRIVING;
}

void Drivetrain::setSpeed(double spd) {
	leftFront.setSpeed(spd);
	leftBack.setSpeed(spd);
	rightFront.setSpeed(spd);
	rightBack.setSpeed(spd);
	state = TELE_DRIVING;
}

void Drivetrain::rotate(double spd) {
	leftFront.setSpeed(spd);
	leftBack.setSpeed(spd);
	rightFront.setSpeed(spd);
	rightBack.setSpeed(spd);
	state = ROTATING;
}

void Drivetrain::runCommand(Command::DriveCommand command, double arg) {
	switch (command) {
	case (Command::ANGLE_ALL_WHEELS):
			setAngle(arg);
			break;
	case (Command::ROTATE_ROBOT):
			rotate(arg);
			break;
	}
}
