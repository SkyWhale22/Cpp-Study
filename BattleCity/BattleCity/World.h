#pragma once

#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Tank.h"
//#include <Windows.h>

class World
{
private:
	static World* m_pWorld;
	World();
	~World();

	Player* m_pPlayer;
	Tank* m_pTank;
public:

	static World* GetInstance()
	{
		if (m_pWorld == nullptr)
			m_pWorld = new World();

		return m_pWorld;
	}

	void FreeInstance() { delete m_pWorld; }

	void PrintTank();
	void MoveTank();
};

