#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem {
private:
	
public:
	SpeedController* cim2;
	SpeedController* cim1;
	RobotDrive* robotDrive;

	DriveTrain();
	void InitDefaultCommand();
	void takeJoystickInputs(Joystick*);
	void Stop();
};
#endif
