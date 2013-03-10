#ifndef WINCH_H
#define WINCH_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Winch: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	SpeedController* cim1;
	SpeedController* cim2;
	SpeedController* cim3;
	SpeedController* cim4;
	SpeedController* BaneBot;
	Encoder* encoder;
	DriverStationLCD* dsLCD;
	DigitalInput* baseLimit;
	
	
	Winch();
	void InitDefaultCommand();
	void Move(Joystick* );
	void Stop();
	
};
#endif
