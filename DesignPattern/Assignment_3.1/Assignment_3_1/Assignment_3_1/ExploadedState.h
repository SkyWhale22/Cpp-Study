#pragma once

#include "TileState.h"

class ExploadedState : public TileState
{
public:
	ExploadedState();
	~ExploadedState();

	virtual void PrintTile() override;
};