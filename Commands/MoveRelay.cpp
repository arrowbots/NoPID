#include "MoveRelay.h"
#include "WPILib.h"

MoveRelay::MoveRelay() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(Robot::relayHold);
}
// Called just before this Command runs the first time
void MoveRelay::Initialize() {
	Robot::relayHold->Stop();
}
// Called repeatedly when this Command is scheduled to run
void MoveRelay::Execute() {
	Robot::relayHold->MoveForward(Robot::oi->getStick2());
	
}

// Make this return true when this Command no longer needs to run execute()
bool MoveRelay::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveRelay::End() {
	Robot::relayHold->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveRelay::Interrupted() {
}


