#pragma once
#include "TankCommand.h"
class CommandMoveDown :
	public TankCommand
{
public:
	CommandMoveDown();

	virtual void Execute(Tank* pTank) override;
	void ChangeToDirectionToDown(Tank* pTank);
};

