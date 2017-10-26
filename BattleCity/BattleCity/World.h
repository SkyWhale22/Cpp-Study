#pragma once

#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Tank.h"
#include "SpriteRenderer.h"
#include <Windows.h>

class World
{
private:
	static World* m_pWorld;
	World();
	~World();

	Tank* m_pPlayer;
	SpriteRenderer m_screenManager;

	CONSOLE_SCREEN_BUFFER_INFO m_screenBuffer;
	HANDLE m_hConsole;
	CONSOLE_CURSOR_INFO m_cursorInfo;
	COORD m_pos;

public:

	static World* GetInstance()
	{
		if (m_pWorld == nullptr)
			m_pWorld = new World();

		return m_pWorld;
	}

	void GameProcess();
	void FreeInstance() { delete m_pWorld; }

	void PrintTank();
	void PrintMap();
	void MoveTank();
};

