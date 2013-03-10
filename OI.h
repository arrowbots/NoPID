#ifndef OI_H
#define OI_H
#include "WPILib.h"
class OI {
private:
	Joystick* stick2;
	Encoder* encoder;
	DigitalInput* limitSwitch1;
	DigitalInput* limitSwitch2;
	Joystick* stick1;
public:
	OI();
	Joystick* getStick1();
	Joystick* getStick2();
};
#endif
