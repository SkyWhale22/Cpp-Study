#pragma once

#include "TileState.h"

class TileStateMachine
{
public:
	enum class State
	{
		kHidden,
		kRevealed,
		kExploaded,

		NUM_States
	};

	TileStateMachine();
	void ChangeState(State newState);
	void PrintTile();
	bool m_isExploaded;

private:
	TileState* m_pState;

public:
	TileState* GetState() { return m_pState; }
};

