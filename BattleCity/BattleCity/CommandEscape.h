#pragma once
#include "TankCommand.h"
class CommandEscape :
	public TankCommand
{
public:
	CommandEscape();

	virtual void Execute(Tank* pTank) override;
	void Escape(Tank* pTank);
};

