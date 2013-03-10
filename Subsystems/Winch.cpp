#include "Winch.h"
#include "../Robotmap.h"
#include "../Commands/MoveWinch.h"
#include "SmartDashboard/SmartDashboard.h"


Winch::Winch() :
	Subsystem("Winch") {
	cim1 = RobotMap::driveTraincim1;
	cim2 = RobotMap::driveTraincim2;
	cim3 = RobotMap::winchcim3;
	cim4 = RobotMap::winchcim4;
	encoder = RobotMap::winchencoder;
	baseLimit = RobotMap::relayLimitSwitch3; //Limit switch at the base of the winch
	BaneBot = RobotMap::BaneBot;
}

void Winch::InitDefaultCommand() {
	SetDefaultCommand(new MoveWinch());
}
void Winch::Move(Joystick* stick) {
	/*
	double distance = encoder->GetDistance();
	
	if (distance <=1000 && distance >=-1000 && stick->GetY()<=-0.05 || stick->GetY() >=0.05) {
		cim1->Set(stick->GetY());
	}
	else {
		cim1->Set(0);
	}
	*/
	//Put new code here
	
	//Code to bring in the winch when button 6 is presses
	if (stick->GetRawButton(6) == true) {
		BaneBot->Set(-0.35);
	} else {
		BaneBot->Set(0.0);
	}

}

void Winch::Stop() {
	cim3->Set(0);
	cim4->Set(0);
	BaneBot->Set(0);
	//encoder->Stop(); //Stop the encoder
	//bencoder->Reset(); //Reset the encoder
}

