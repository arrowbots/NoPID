#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveWithJoysticks.h"
#include "Commands/MoveWinch.h"
#include "Commands/MoveRelay.h"
#include "RobotMap.h"

OI::OI() {
	// Process operator interface input here.
	stick2 = new Joystick(2);
	encoder = RobotMap::winchencoder;
	limitSwitch1 = RobotMap::relayLimitSwitch1;
	limitSwitch2 = RobotMap::relayLimitSwitch2;
	stick1 = new Joystick(1);
	
     
    // SmartDashboard Buttons
	SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
	SmartDashboard::PutData("DriveWithJoysticks", new DriveWithJoysticks());
	SmartDashboard::PutData("MoveWinch", new MoveWinch());

	encoder = RobotMap::winchencoder;
	limitSwitch1 = RobotMap::relayLimitSwitch1;
	limitSwitch2 = RobotMap::relayLimitSwitch2;
	
	SmartDashboard::PutNumber("encoder %f10",encoder->GetDistance());
	SmartDashboard::PutNumber("limit switch 1",limitSwitch1->Get());
	SmartDashboard::PutNumber("limit switch 2",limitSwitch2->Get());
}
Joystick* OI::getStick2() { //Return value for getStick2
	return stick2;
}
Joystick* OI::getStick1() { //Return value for getStick1
	return stick1;
}

