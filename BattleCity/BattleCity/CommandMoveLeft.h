#pragma once
#include "TankCommand.h"
class CommandMoveLeft :
	public TankCommand
{
public:
	CommandMoveLeft();

	virtual void Execute(Tank* pTank) override;
	void ChangeDirectionToLeft(Tank* pTank);
};

