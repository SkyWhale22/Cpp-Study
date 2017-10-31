#pragma once

#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Tank.h"

#include "SpriteRenderer.h"
#include "CollisionChecker.h"

#include <Windows.h>

class Input;

class World
{
private:
	static World* m_pWorld;
	World();
	~World();

	//Tank* m_pPlayer;
	Player* m_pPlayer;
	Enemy* m_pEnemy[2];
	Map* m_pMap;
	Input* m_pInput;

	SpriteRenderer m_screenManager;
	CollisionChecker m_colChecker;

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
	
	bool OnCollide(Tank* pTank1, Tank* pTank2);
	void EnemyMovement(Enemy* pTank);

	void MoveTank(Tank* pTank);
	void MoveShells(Tank* pTank);
	void PrintTank(Tank* pTank, SpriteRenderer::Color color);
	void PrintShell(Tank* pTank);
	void PrintArena();
	void GoToXY(int x, int y);
	void ShellStatusCheck();
};

