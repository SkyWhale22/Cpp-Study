#pragma once
#include "TankCommand.h"
class CommandFire :
	public TankCommand
{
public:
	CommandFire();

	virtual void Execute(Tank* pTank) override;
	void Fire(Tank* pTank);
};

