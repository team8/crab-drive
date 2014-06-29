#include "Drivetrain.h"


using namespace Krabbs;

Drivetrain::Drivetrain() : Subsystem() {
	
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
	
}
