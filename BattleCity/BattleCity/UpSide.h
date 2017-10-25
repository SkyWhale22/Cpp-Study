#pragma once
#include "TankState.h"
class UpSide :
	public TankState
{
public:
	UpSide();
	~UpSide();

	void ReadSprite(char* pName) override;
};

