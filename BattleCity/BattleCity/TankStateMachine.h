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
	Direction m_dir;

public:
	std::string& GetSprite() { return m_pState->GetSprite(); }
	TankState* GetState() { return m_pState; }
	Direction GetDirection() { return m_dir; }
};

