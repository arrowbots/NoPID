
#include "DriveWithJoysticks.h"

DriveWithJoysticks::DriveWithJoysticks() {
	Requires(Robot::driveTrain);
}

// Called just before this Command runs the first time
void DriveWithJoysticks::Initialize() {
	Robot::driveTrain->Stop();
}
// Called repeatedly when this Command is scheduled to run
void DriveWithJoysticks::Execute() {
	Robot::driveTrain->takeJoystickInputs(Robot::oi->getStick1());
}
// Make this return true when this Command no longer needs to run execute()
bool DriveWithJoysticks::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void DriveWithJoysticks::End() {
	Robot::driveTrain->Stop();
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithJoysticks::Interrupted() {
}
