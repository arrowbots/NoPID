#include "DriveTrain.h"
#include "../Robotmap.h"
#include "../Commands/DriveWithJoysticks.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	cim2 = RobotMap::driveTraincim2;
	cim1 = RobotMap::driveTraincim1;
	robotDrive = RobotMap::driveTrainRobotDrive;
}
    
void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	
	SetDefaultCommand(new DriveWithJoysticks());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::takeJoystickInputs(Joystick* stick){
	robotDrive->ArcadeDrive(-(stick->GetY()),-(stick->GetX()));
}
void DriveTrain::Stop(){
	robotDrive->Drive(0,0);
}
