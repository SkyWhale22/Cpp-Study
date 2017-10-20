#pragma once

#include <iostream>
#include "Character.h"

using std::cout;
using std::endl;

class TileStateMachine;

class TileState
{
public:
	
	virtual void PrintTile() = 0;

protected:
	TileStateMachine* m_pStateMachine;
};

