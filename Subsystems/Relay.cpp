#include "RelayHold.h"
#include "../Robotmap.h"
#include "../Commands/MoveRelay.h"
#include "SmartDashboard/SmartDashboard.h"
int stopForwardOld = 0;
int stopBackOld = 0;
RelayHold::RelayHold() :
	Subsystem("Relay") {
	spike1 = RobotMap::relaySpike1;
	limitSwitch1 = RobotMap::relayLimitSwitch1;
	limitSwitch2 = RobotMap::relayLimitSwitch2;
}

void RelayHold::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new MoveRelay());

	}
void RelayHold::MoveForward(Joystick* stick) {
	bool debug = true;
	int stopBack = limitSwitch2->Get();
	int stopForward = limitSwitch1->Get();
	if (stopForward != stopForwardOld || stopBack != stopBackOld && debug == true) {
		//if forward limit switch changes or back limit switch changes
		stopForwardOld = stopForward;
		stopBackOld = stopBack;
		printf("Forward %d\nBack %d\n", stopForward, stopBack);
	}
	if (stick->GetRawButton(1) == true && stopBack == 1) {
		spike1->Set(Relay::kOn); 
		spike1->Set(Relay::kReverse); //Tell actuator to go forward
		//printf("It's going Backward! \n");
	} else if (stick->GetRawButton(2) == true && stopForward == 1) {
		spike1->Set(Relay::kOn);
		spike1->Set(Relay::kForward); // Tell actuator to go forward
	//	printf("It's going Forward! \n");
	} else {
		spike1->Set(Relay::kOff);
	}

}

void RelayHold::Stop() {
	spike1->Set(Relay::kOff);
}


