#pragma once

#include "TankState.h"

class TankStateMachine
{	
public:
	enum class Direction
	{
		kUp,
		kDown,
		kRight,
		kLeft,

		kDirNum
	};

	TankStateMachine();
	~TankStateMachine();

	void ChangeDirection(Direction newDir);
	void PrintSprite(char* pName);
	void DestroyState();
private:
	TankState* m_pState;
public:
	TankState* GetState() { return m_pState; }
};

