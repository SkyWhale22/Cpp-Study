#pragma once
#include "TankCommand.h"

class CommandMoveRight :
	public TankCommand
{
public:
	CommandMoveRight();

	virtual void Execute(Tank* pTank) override;

	void ChangeDirectionToRight(Tank* pTank);
};

