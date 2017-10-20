#pragma once

#include "TileState.h"

class RevealedState : public TileState
{
public:
	RevealedState();
	~RevealedState();

	virtual void PrintTile() override;
};

