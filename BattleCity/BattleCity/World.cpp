#include "World.h"
#include "Player.h"
#include "Map.h"
#include "Vector2.h"
#include "Input.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "TankStateMachine.h"
World* World::m_pWorld = nullptr;

World::World()
{
	m_pPlayer = new Player();
	m_pEnemy[0] = new Enemy();
	m_pEnemy[1] = new Enemy();
	m_pMap = new Map();
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	m_pos.X = 0;
	m_pos.Y = 0;
	m_screenManager.Init();
	m_pMap->ReadMap();
}

World::~World()
{
	//Map::GetInstance()->FreeInstance();
	delete m_pMap;
	m_pMap = nullptr;
	delete m_pPlayer;
	m_pPlayer = nullptr;
	delete m_pEnemy[0];
	m_pEnemy[0] = nullptr;
	delete m_pEnemy[1];
	m_pEnemy[1] = nullptr;
}

void World::GameProcess()
{
	char input;

	//---------------------------------------
	// Let's change it to function pointer
	//---------------------------------------
	while (true)
	{
		Sleep(40); 

		//-------------------------------------------------
		// Print eveny stuffs.
		//-------------------------------------------------
		PrintArena();
		PrintTank(m_pPlayer, SpriteRenderer::Color::kYellow);

		for(int i = 0; i < 2; ++i)
			PrintTank(m_pEnemy[i], SpriteRenderer::Color::kSilver);

		input = m_pInput->GetInput();
		
		// Changes player's position regarding as input.
		m_pPlayer->GetInput(input);

		// Moves player tank.
		if (OnCollide(m_pPlayer, m_pEnemy[0]) == false && m_pMap->CheckEndOfMapForTank(m_pPlayer->GetStateMachine()->GetDirection(), m_pPlayer->GetVector()) == false)
			MoveTank(m_pPlayer);
		//OnCollide(m_pPlayer, m_pEnemy[0]);
		EnemyMovement(m_pEnemy[0]);
		EnemyMovement(m_pEnemy[1]);

		MoveShells(m_pPlayer);
		MoveShells(m_pEnemy[0]);
		MoveShells(m_pEnemy[1]);

		PrintShell(m_pPlayer);
		PrintShell(m_pEnemy[0]);
		PrintShell(m_pEnemy[1]);

		// Escapes this loop
		if (input == 'q')
			break;
		 
	}
}

bool World::OnCollide(Tank* pTank1, Tank* pTank2)
{
	bool isCollided = false;

	

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for(int k = 0; k < 3; ++k)
				isCollided = m_colChecker.ColBetweenTwoObjs(pTank1->GetVector()->GetX() + i, pTank1->GetVector()->GetY(), pTank2->GetVector()->GetX() + k, pTank2->GetVector()->GetY() + j);
		}
		if (isCollided)
			break;
	}

	return isCollided;
}

void World::EnemyMovement(Enemy* pTank)
{
	if (m_pMap->CheckEndOfMapForTank(pTank->GetStateMachine()->GetDirection(), pTank->GetVector()) == false)
	{
		if(OnCollide(pTank, m_pPlayer) == false)
			pTank->MoveEnemyTank();
	}
	else
		pTank->SetEnemyStatus();
}

void World::MoveTank(Tank* pTank)
{
	switch (pTank->GetStateMachine()->GetDirection())
	{
	case TankStateMachine::Direction::kDown:
		pTank->Move(0, 1);
		break;
	case TankStateMachine::Direction::kUp:
		pTank->Move(0, -1);
		break;
	case TankStateMachine::Direction::kRight:
		pTank->Move(1, 0);
		break;
	case TankStateMachine::Direction::kLeft:
		pTank->Move(-1, 0);
		break;
	}

}

void World::MoveShells(Tank * pTank)
{
	if (pTank->GetShell() != nullptr)
	{
		if (m_pMap->CheckEndOfMapForShell(pTank->GetShell()->GetDirection(), &pTank->GetShell()->GetPosition()) == false)
			pTank->GetShell()->Move();
		else
			pTank->DeleteShell();
	}
}

void World::PrintTank(Tank* pTank, SpriteRenderer::Color color)
{
	m_screenManager.PrintTanks(pTank->GetStateMachine()->GetSprite(), pTank->GetStateMachine()->GetDirection(), *pTank->GetVector(), color);
}

void World::PrintShell(Tank* pTank)
{
	if (pTank->GetShell() != nullptr)
		m_screenManager.PrintShells(pTank->GetShell()->GetSprite(), pTank->GetShell()->GetDirection(), pTank->GetShell()->GetPosition());
}

void World::PrintArena()
{
	m_screenManager.PrintArena(m_pMap->GetMapSprite("OutLine"));
	m_screenManager.PrintArena(m_pMap->GetMapSprite("TopBottom"));
	m_screenManager.PrintArena(m_pMap->GetMapSprite("Side"));
	m_screenManager.PrintArena(m_pMap->GetMapSprite("OutLineSide"));
}

void World::GoToXY(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void World::ShellStatusCheck()
{
		//GoToXY(2, j);

	//	GoToXY(25, e);

	/*
	GoToXY(30, 19);
	std::cout << m_pPlayer->GetVector()->GetX() << " : " << m_pPlayer->GetVector()->GetY() << std::endl;

	GoToXY(30, 20);

	std::cout << m_pPlayer->m_shootCount << std::endl;

	GoToXY(30, 21);
	std::cout << m_pEnemy[0]->GetVector()->GetX() << " : " << m_pEnemy[0]->GetVector()->GetY() << std::endl;

	GoToXY(30, 22);
	std::cout << m_pEnemy[1]->GetVector()->GetX() << " : " << m_pEnemy[1]->GetVector()->GetY() << std::endl;
	*/
}


