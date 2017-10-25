#pragma once
#include "TankState.h"
class LeftSide :
	public TankState
{
public:
	LeftSide();
	~LeftSide();

	void ReadSprite(char* pName) override;
};

