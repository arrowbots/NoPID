#include "Winch.h"
#include "../Robotmap.h"
#include "../Commands/MoveWinch.h"
#include "SmartDashboard/SmartDashboard.h"

static int setpoint=0;
static int setpointGain=100;
static double encoderValue=0;
static double stickY=0;
static double PropGain= 0.005;
static int PropMax=100;
static double cimSpeed=0;

//Declare prototype so that we can put our function anywhere.
int PropSpeed (int set, double encoder, double gain, int max);

Winch::Winch() :
  Subsystem("Winch") {
  cim1 = RobotMap::driveTraincim1; //Test cim
  cim2 = RobotMap::driveTraincim2; //Not sure why this is even here!!! JAVED!!
  cim3 = RobotMap::winchcim3; //Winch cim
  cim4 = RobotMap::winchcim4; //Winch cim
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
  
  //Daniel's Proportional Code :)
  encoderValue=encoder->GetDistance(); //Store the encoder value 
  if (stick->GetY() >= 0.05) {
    setpoint += (stick->GetY())*setpointGain;
  } else if (stick->GetY() <= -0.05) {
    setpoint -= (stick->GetY())*setpointGain;
  }
  cimSpeed = PropSpeed(setpoint, encoderValue, PropGain, PropMax);
  cim1->Set(cimSpeed);

  //Code to bring in the winch when button 6 is pressed
  if (stick->GetRawButton(6) == true) {
    BaneBot->Set(-0.35);
  } else {
    BaneBot->Set(0.0);
  }
}

int PropSpeed (int set, double encoder, double gain, int max) {
  int difference = (set - encoder);
  if (difference > max) {
    difference= max;
  } else if (difference < (max*(-1))) {
    difference=max*(-1);
  }
  int out = difference*gain;
  return out;
}

void Winch::Stop() {
	cim3->Set(0);
	cim4->Set(0);
	BaneBot->Set(0);
	//encoder->Stop(); //Stop the encoder
	//bencoder->Reset(); //Reset the encoder
}

