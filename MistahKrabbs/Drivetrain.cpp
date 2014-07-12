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
	state = State::IDLE;
	parallels = LR_PARALLEL; //should actually go through routine to find out.
	invert = 1; //should actually go through routine
	leftFront.init();
	leftBack.init();
	rightFront.init();
	rightBack.init();
	gyro.Reset();
	currentAngle = targetAngle = (gyro.GetAngle() >=360) ? modulo(360, gyro.GetAngle()) : gyro.GetAngle();
}

void Drivetrain::update() {
	switch (state) {
	case State::IDLE:
		leftFront.disable();
		leftBack.disable();
		rightFront.disable();
		rightBack.disable();
		leftFront.update();
		leftBack.update();
		rightFront.update();
		rightBack.update();
		break;
	case State::TELE_DRIVING:
		leftFront.update();
		leftBack.update();
		rightFront.update();
		rightBack.update();
		break;
	case State::ROTATING:
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
	state = State::IDLE;
}

void Drivetrain::setAngle(double ang) { // expects -180 to 180
	targetAngle = ang;
	leftFront.setAngle(targetAngle);
	rightFront.setAngle(targetAngle);
	leftBack.setAngle(targetAngle);
	rightBack.setAngle(targetAngle);
	state = State::TELE_DRIVING;
}

void Drivetrain::setSpeed(double spd) { //expects -1 to 1. getMagnitude returns 0 to 1
	leftFront.setSpeed(spd);
	leftBack.setSpeed(spd);
	rightFront.setSpeed(spd);
	rightBack.setSpeed(spd);
	state = State::TELE_DRIVING;
}

void Drivetrain::rotate(double spd) { //expects -1 to 1. NOT ANGLE
	
	updateQuadrant();

	if (parallels == Parallel::LR) {
		leftFront.setSpeed(spd*invert);
		leftBack.setSpeed(spd*invert); // for all these (+) and (-) might need to be switched
		rightFront.setSpeed(-spd*invert);
		rightFront.setSpeed(-spd*invert);
	} else if (parallels == Parallel::FB) {
		leftFront.setSpeed(spd*invert);
		rightFront.setSpeed(spd*invert);
		leftBack.setSpeed(-spd*invert); // for all these (+) and (-) might need to be switched
		rightBack.setSpeed(-spd*invert);
	}
	state = State::ROTATING;
}

void Drivetrain::runCommand(Command::DriveCommand command, double arg, double arg2) {
	case (Command::ANGLE_ALL_WHEELS):
		setAngle(arg); //angle
		setSpeed(arg2); //speed.
		break;
	case (Command::ROTATE_ROBOT):
		rotate(arg);
		break;
	}
}

void Drivetrain::updateQuadrant() {
	double avgAng = (leftFront.getAngle() + leftBack.getAngle() + rightFront.getAngle() + rightBack.getAngle()) / 4.0;
	
	if (-180 + (FB_ANGLE / 2) > avgAng > -180) { //1. LR
		invert = 1;
	} else if (0 - (FB_ANGLE / 2) > avgAng > -180 + (FB_ANGLE / 2)) { //2. FB
		invert = 1;
	} else if (0 + (FB_ANGLE / 2) > avgAng > 0 - (FB_ANGLE / 2)) { //3. LRI
		invert = -1;
	} else if (180 - (FB_ANGLE / 2) > avgAng > 0 + (FB_ANGLE / 2)) { //4. FBI
		invert = -1;
	} else if (180 > avgAng > 180 - (FB_ANGLE / 2)) { //5. LR
		invert = 1;
	}
}