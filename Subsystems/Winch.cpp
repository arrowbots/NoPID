#include "Winch.h"
#include "../Robotmap.h"
#include "../Commands/MoveWinch.h"
#include "SmartDashboard/SmartDashboard.h"

double encoderOld = 0;
double encoderMax = 4000;
double encoderMin = -4000;

void Winch::InitDefaultCommand() {
	SetDefaultCommand(new MoveWinch());
}

Winch::Winch() :
			Subsystem("Winch") {

	cim1 = RobotMap::driveTraincim1; //Test cim
	cim3 = RobotMap::winchcim3; //Winch cim
	cim4 = RobotMap::winchcim4; //Winch cim
	encoder = RobotMap::winchencoder;
	baseLimit = RobotMap::relayLimitSwitch3; //Limit switch at the base of the winch
	BaneBot = RobotMap::BaneBot;
	frisbeeDumper=RobotMap::frisbeeDumper;

}

void Winch::Move(Joystick* stick) {

	double distance = encoder->GetDistance(); // Get distance from encoder, and store it in a variable.

	//Check to see if the distance is greater than -4000 (which is represented by encoderMIn), and make sure joystic value 
	if ((distance >= encoderMin) && stick->GetY() >= 0.05) { 
		printf("winch extending\n");
		//If the distance is less than or equal to 2000 and distance is less than or equal to 4000.
		if (distance >= (2000) && distance <= encoderMax) {
			cim1->Set(0.7); //Set the cim speed to 70% counterclockwise
			printf("slow down winch\n");
		} //if the distance is more than encoderMax(4000) and distance is less than 10000
		else if (distance >= encoderMax && distance <=10000){
			cim1->Set(0);//don't move the winch
			printf("WINCH CANNOT MOVE\n");
		}
		else {
			cim1->Set(stick->GetY());
		}

		//If the distance is less than or equal to 4000 (which is represented by encoderMax).
	} else if ((distance <= encoderMax) && stick->GetY() <= -0.05) {
		printf("winch retracting\n");
		//if the encoder distance is less than -2000 and the distance is more than encoderMin(-4000)
		if (distance <= (-2000 )&& distance >= encoderMin) {
			printf("slow down winch retraction\n");
			cim1->Set((-0.7));
		}
		//if the encoder distance is less than encoderMin(-4000) and encoder distance is more than -10000
		else if (distance <= encoderMin && distance >=-10000){
			cim1->Set(0);
			printf("WINCH CANNOT MOVE\n");
		}
		//else just operate normally
		else {
			cim1->Set(stick->GetY());
		}
	//else don't activate cim
	} else {
		cim1->Set(0);
	}

	//Code to bring in the winch when button 6 is pressed
	if (stick->GetRawButton(6) == true) {
		BaneBot->Set(-0.35);
	} else {
		BaneBot->Set(0.0);
	}

	//print back encoder distance
	if (encoderOld != distance) {
		printf("Encoder: %d \n", int(distance));
		encoderOld = distance;
	}

	//reset the encoder
	if (stick->GetRawButton(7) == true) {
		encoder->Reset();
	}
	
	if(stick->GetRawButton(3)==true && stick->GetRawButton(11)==true){
		frisbeeDumper->Set(0.45);
	}
}

void Winch::Stop() {
	cim3->Set(0);
	cim4->Set(0);
	BaneBot->Set(0);
	encoder->Stop(); //Stop the encoder
	encoder->Reset(); //Reset the encoder
}

