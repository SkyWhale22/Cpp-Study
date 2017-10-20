#pragma once
#include "TileState.h"

class HiddenState : public TileState
{
public:
	HiddenState();
	~HiddenState();

	virtual void PrintTile() override;
};

