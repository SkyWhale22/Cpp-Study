#include "World.h"
#include "Player.h"
#include "Map.h"
#include <iostream>

World* World::m_pWorld = nullptr;

World::World()
{
	m_pPlayer = new Player();

	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	m_pos.X = 0;
	m_pos.Y = 0;
}

World::~World()
{
	Map::GetInstance()->FreeInstance();
	delete m_pPlayer;
}

void World::GameProcess()
{
	system("cls");
	bool keepGoing = true;

	while (keepGoing)
	{
		Map::GetInstance()->ReadMap();
		m_screenManager.Init();
		PrintTank();
		keepGoing = m_pPlayer->Update();
	}
}

void World::PrintTank()
{
	m_screenManager.PrintOnCoord(m_pPlayer->GetStateMachine()->GetState()->GetSprite(), *m_pPlayer->GetVector());
}

void World::PrintMap()
{
	m_screenManager.PrintOnCoord(m_pPlayer->GetStateMachine()->GetState()->GetSprite(), *m_pPlayer->GetVector());
}

void World::MoveTank()
{
	CONSOLE_SCREEN_BUFFER_INFO screenBuffer;
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &screenBuffer);

	COORD pos;
	pos.X = 10;
	pos.Y = 10;
	SetConsoleCursorPosition(hConsole, pos);

	PrintTank();
}