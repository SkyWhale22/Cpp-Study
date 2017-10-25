#pragma once
#include "TankState.h"
class RightSide :
	public TankState
{
public:
	RightSide();
	~RightSide();

	void ReadSprite(char* pName) override;
};

