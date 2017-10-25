#pragma once
#include "TankState.h"
class DownSide :
	public TankState
{
public:
	DownSide();
	~DownSide();

	void ReadSprite(char* pName) override;
};

