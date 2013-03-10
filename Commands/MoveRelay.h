#ifndef MOVERELAY_H
#define MOVERELAY_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class MoveRelay: public Command {
public:
	MoveRelay();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
