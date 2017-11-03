#pragma once

class Tank;

class TankCommand
{
public:
	virtual ~TankCommand() {};
	virtual void Execute(Tank* pTank) = 0;
};