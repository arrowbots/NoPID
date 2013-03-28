#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	static SpeedController* driveTraincim2;
	static SpeedController* driveTraincim1;
	static SpeedController* BaneBot;
	static SpeedController* frisbeeDumper;
	static RobotDrive* driveTrainRobotDrive;
	static SpeedController* winchcim3;
	static SpeedController* winchcim4;
	static DriverStationLCD* dsLCD;
	static Encoder* winchencoder;
	static DigitalInput* chanA;
	static DigitalInput* chanB;
	static Relay* relaySpike1; //Left relay
	static DigitalInput* relayLimitSwitch1; //Limit switch one
	static DigitalInput* relayLimitSwitch2; //Limit switch two
	static DigitalInput* relayLimitSwitch3; //Limit switch three
	//Init
	static void init();
};
#endif
