#ifndef MOVEWINCH_H
#define MOVEWINCH_H
#include "Commands/Subsystem.h"
#include "../Robot.h"

class MoveWinch: public Command {
public:
	MoveWinch();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
