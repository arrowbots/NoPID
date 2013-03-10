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
	//printf("Base Limit %d and Encoder %f \n",baseLimit->Get(), encoder->GetDistance());
	//if the y axis of the stick has a value greater than 0.025 and less than -0.025

	/*if (stick->GetY() > 0.05 && baseLimit->Get() == 1) {
	 //sets the speed of the motors to 75% of the value of the stick
	 cim3->Set(stick->GetY()*0.75);
	 cim4->Set(stick->GetY()*0.75);
	 } else if (stick->GetY() < -0.05) {
	 cim3->Set(stick->GetY()*0.75);
	 cim4->Set(stick->GetY()*0.75);
	 } else if (stick->GetY() < 0.05 && stick->GetY() > -0.05) {
	 cim3->Set(0);
	 cim4->Set(0);
	 }
	 */
	//printf("Distance: %f4 \n",encoder->GetDistance());
	/*double distance = encoder->GetDistance();
	if (distance <= (1000) && stick->GetY() <= -0.05) {
		printf("Greater than -1000\n");
		printf("Distance: %f4 \n",encoder->GetDistance());
		cim1->Set(stick->GetY());
	} else if (distance >= (-1000) && stick->GetY() >= 0.05) {
		printf("Less than 1000\n");
		cim1->Set(stick->GetY());
		printf("Distance: %f4 \n",encoder->GetDistance());
	} else {
		cim1->Set(0);
	}
	*/
	
	double distance = encoder->GetDistance();
	
	if (distance <=1000 && distance >=-1000 && stick->GetY()<=-0.05 || stick->GetY() >=0.05) {
		cim1->Set(stick->GetY());
	}
	else {
		cim1->Set(0);
	}
	
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

