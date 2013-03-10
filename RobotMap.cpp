
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

DriverStationLCD* RobotMap::dsLCD = NULL;
SpeedController* RobotMap::driveTraincim2 = NULL;
SpeedController* RobotMap::driveTraincim1 = NULL;
SpeedController* RobotMap::BaneBot = NULL;
RobotDrive* RobotMap::driveTrainRobotDrive = NULL;
SpeedController* RobotMap::winchcim3 = NULL;
SpeedController* RobotMap::winchcim4 = NULL;
Encoder* RobotMap::winchencoder = NULL;
Relay* RobotMap::relaySpike1 = NULL;
//Relay* RobotMap::relaySpike2 = NULL;
DigitalInput* RobotMap::relayLimitSwitch1 = NULL;
DigitalInput* RobotMap::relayLimitSwitch2 = NULL;
DigitalInput* RobotMap::relayLimitSwitch3 = NULL;
//DigitalInput* RobotMap::chanA;
//DigitalInput* RobotMap::chanB;

const float PI = 3.14159;
void RobotMap::init() {
	LiveWindow* lw = LiveWindow::GetInstance();
	DriverStationLCD* dsLCD = DriverStationLCD::GetInstance();
	
	//Left relay, that is in use 
	relaySpike1 = new Relay(1, 1);
	lw->AddActuator("Relay", "Spike 1", relaySpike1);
	
	//Unused relay
	//relaySpike2 = new Relay(1, 2);
	//lw->AddActuator("Relay", "Spike 2", relaySpike2);
	
	//One limitswitch
	relayLimitSwitch1 = new DigitalInput(1, 3);
	lw->AddSensor("Relay", "Limit Switch 1", relayLimitSwitch1);
	relayLimitSwitch2 = new DigitalInput(1,4);
	lw->AddSensor("Relay", "Limit Switch 2", relayLimitSwitch2);
	relayLimitSwitch3 = new DigitalInput(1,5);
	//lw->AddSensor("Relay", "Limit Switch 3", relayLimitSwitch3);


	
	//Just some digital input allocations, for Digital I/O
	//DigitalInput* chanA = new DigitalInput(1);
	//DigitalInput* chanB= new DigitalInput(2);
	
	
	driveTraincim2 = new Jaguar(1, 2);
	lw->AddActuator("DriveTrain", "cim2", (Jaguar*) driveTraincim2);
	
	driveTraincim1 = new Jaguar(1, 1);
	lw->AddActuator("DriveTrain", "cim1", (Jaguar*) driveTraincim1);
	
	BaneBot= new Victor(1,5); //Add AndyMark Motor control/ map it
	
	driveTrainRobotDrive = new RobotDrive(driveTraincim1, driveTraincim2);

	driveTrainRobotDrive->SetSafetyEnabled(true);
    driveTrainRobotDrive->SetExpiration(0.1);
    driveTrainRobotDrive->SetSensitivity(0.5);
    driveTrainRobotDrive->SetMaxOutput(1.0);
        
	winchcim3 = new Jaguar(1, 3);//original cim port
	lw->AddActuator("Winch", "cim3", (Jaguar*) winchcim3);
	
	winchcim4 = new Jaguar(1, 4);//another original cim port
	lw->AddActuator("Winch", "cim4", (Jaguar*) winchcim4);
	

	winchencoder = new Encoder(1,4,1,5, false, Encoder::k4X); // Where Encoder(1,1,1,2) indicate Module 1/ Channel A, and Module 1 Channel B
	lw->AddSensor("Winch", "encoder", winchencoder);
	winchencoder->SetDistancePerPulse(2*PI/Encoder::k4X);
	
	//Get Digital Input, which is either 1 or 0
	int digitalInput1= RobotMap::relayLimitSwitch1->Get();
	int digitalInput2= RobotMap::relayLimitSwitch2->Get();
	int digitalInput3= RobotMap::relayLimitSwitch3->Get();

	
        //winchencoder->SetPIDSourceParameter(Encoder::kRate); // For PID stuff
        winchencoder->Start(); 
        
      //  float winchDouble = RobotMap::winchencoder->GetDistance(); //Create a variable to store the winch Get Distance value
        //Send encoder value back to little lcd
    	//dsLCD->Printf(DriverStationLCD::kUser_Line1,1,"Encoder: %f",winchDouble);
    	//dsLCD->Printf(DriverStationLCD::kUser_Line2,1,"Limit Switch 1: %d",digitalInput1); //Output limit switch one value
    	//dsLCD->Printf(DriverStationLCD::kUser_Line3,1,"Limit Switch 2: %d",digitalInput2); //Output limit switch two value
    	///dsLCD->Printf(DriverStationLCD::kUser_Line4,1,"Limit Switch 3: %d",digitalInput3); //Output limit switch two value
    	dsLCD->UpdateLCD();
}
