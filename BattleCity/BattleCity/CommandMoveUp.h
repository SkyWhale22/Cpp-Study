#pragma once
#include "TankCommand.h"
class CommandMoveUp :
	public TankCommand
{
public:
	CommandMoveUp();

	virtual void Execute(Tank* pTank) override;
	void ChangeDirectionToUp(Tank* pTank);
};

