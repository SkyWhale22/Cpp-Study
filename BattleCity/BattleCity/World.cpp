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

//----------------------------------------------------------
// TODO:
//	Making a vector that contains every tanks.
//	So that I could print tanks in one shot.
//----------------------------------------------------------
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

	for (int i = 0; i < 2; ++i)
	{
		delete m_pEnemy[i];
		m_pEnemy[i] = nullptr;
	}
}

void World::GameProcess()
{
	char input = NULL;

	//---------------------------------------
	// Let's change it to function pointer
	//---------------------------------------
	while (true)
	{
		Sleep(47); 

		//-------------------------------------------------
		// Print eveny stuffs.
		//-------------------------------------------------
		PrintArena();
		PrintTank(m_pPlayer, SpriteRenderer::Color::kYellow);

		for (int i = 0; i < 2; ++i)
		{
			if(m_pEnemy[i] != nullptr)
			PrintTank(m_pEnemy[i], SpriteRenderer::Color::kSilver);
		}

		// Changes player's position regarding as input.
		m_pPlayer->Update();

		// MoveE
		PlayerMovement();
		EnemyMovement();

		ShellCollisionCheckPlayer();

		for (int i = 0; i < 2; ++i)
		{
			if (m_pEnemy[i] != nullptr)
				ShellCollisionCheckEnemy(m_pEnemy[i]);
		}

		PrintShell(m_pPlayer);

		for (int i = 0; i < 2; ++i)
		{
			if (m_pEnemy[i] != nullptr)
				PrintShell(m_pEnemy[i]);
		}

		ShellStatusCheck();
		// Escapes this loop
		if (m_pPlayer->CheckToEscape() == true || m_pPlayer->GetHP() <= 0)
		{
			m_screenManager.GameOverMessage();
			_getch();
			break;
		}
		 
	}
}

bool World::OnCollideTtT(Tank* pTank1, Tank* pTank2)
{
	bool isCollided = false;

	switch (pTank1->GetStateMachine()->GetDirection())
	{
	case TankStateMachine::Direction::kUp:
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					isCollided = m_colChecker.ColBetweenTwoObjs(pTank1->GetVector()->GetX() + i, pTank1->GetVector()->GetY() - 1, pTank2->GetVector()->GetX() + k, pTank2->GetVector()->GetY() + j);
					
					if (isCollided)
						return true;
				}
			}
		}

		break;
	case TankStateMachine::Direction::kDown:
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					isCollided = m_colChecker.ColBetweenTwoObjs(pTank1->GetVector()->GetX() + i, pTank1->GetVector()->GetY() + 3, pTank2->GetVector()->GetX() + k, pTank2->GetVector()->GetY() + j);
					if (isCollided)
						return true;
				}
			}
		}

		break;
	case TankStateMachine::Direction::kRight:
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					isCollided = m_colChecker.ColBetweenTwoObjs(pTank1->GetVector()->GetX() + 3, pTank1->GetVector()->GetY() + i, pTank2->GetVector()->GetX() + j, pTank2->GetVector()->GetY() + k);
					if (isCollided)
						return true;
				}
			}
		}

		break;
	case TankStateMachine::Direction::kLeft:
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					isCollided = m_colChecker.ColBetweenTwoObjs(pTank1->GetVector()->GetX() - 1, pTank1->GetVector()->GetY() + i, pTank2->GetVector()->GetX() + j, pTank2->GetVector()->GetY() + k);
					if (isCollided)
						return true;
				}
			}
		}
		break;
	default:
		break;
	}

	return false;
}

void World::PlayerMovement()
{
	bool canMove;

	for (int i = 0; i < 2; ++i)
	{
		if (OnCollideTtT(m_pPlayer, m_pEnemy[i]) == false)
			canMove = true;
		else
		{
			canMove = false;
			break;
		}
	}
		
	// Moves player tank.
	if (canMove && m_pMap->CheckEndOfMapForTank(m_pPlayer->GetStateMachine()->GetDirection(), m_pPlayer->GetVector()) == false)
		MoveTank(m_pPlayer);
}

void World::ShellCollisionCheckPlayer()
{

	if (m_pPlayer->GetShell() != nullptr)
	{
		bool canMove;

		for (int i = 0; i < 2; ++i)
		{
			if (m_pEnemy[i] != nullptr && OnCollideTtS(m_pPlayer, m_pEnemy[i]) == false)
				canMove = true;
			else
			{
				canMove = false;
				DestroyAndGenerateEnemyTank(i);
				break;
			}
		}

		if (canMove)
			MoveShells(m_pPlayer);
		else
		{
			dynamic_cast<Tank*>(m_pPlayer)->DeleteShell();
			m_pPlayer->AddScore();
			//m_pPlayer->AddScore();
		}
	}
}

void World::ShellCollisionCheckEnemy(Tank* pTank)
{
	if (pTank->GetShell() != nullptr)
	{
		if (OnCollideTtS(pTank, m_pPlayer) == false)
			MoveShells(pTank);
		else
		{
			pTank->DeleteShell();
			m_pPlayer->GetDamage();
		}
	}
}

void World::EnemyMovement()
{
	for (int i = 0; i < 2; ++i)
	{
		if (m_pEnemy[i] != nullptr && m_pMap->CheckEndOfMapForTank(m_pEnemy[i]->GetStateMachine()->GetDirection(), m_pEnemy[i]->GetVector()) == false)
		{
			if (OnCollideTtT(m_pEnemy[i], m_pPlayer) == false)
				m_pEnemy[i]->Update();
		}
		else
			m_pEnemy[i]->ResetDirection();
	}
}


bool World::OnCollideTtS(Tank* pTank1, Tank * pTank2)
{
	bool isCollided = false;

	for (int j = 0; j < 3; ++j)
	{
		for (int k = 0; k < 3; ++k)
		{
			isCollided = m_colChecker.ColBetweenTwoObjs(pTank1->GetShell()->GetPosition()->GetX(), pTank1->GetShell()->GetPosition()->GetY(), pTank2->GetVector()->GetX() + j, pTank2->GetVector()->GetY() + k);
			if (isCollided == true)
				return isCollided;
		}
	}

	return isCollided;
}


void World::MoveTank(Tank* pTank)
{
	pTank->CheckMovingDirection();
}

void World::MoveShells(Tank * pTank)
{
	if (m_pMap->CheckEndOfMapForShell(pTank->GetShell()->GetDirection(), pTank->GetShell()->GetPosition()) == false)
			pTank->GetShell()->Move();
		else
			pTank->DeleteShell();
}

void World::PrintTank(Tank* pTank, SpriteRenderer::Color color)
{
	m_screenManager.PrintTanks(pTank->GetStateMachine()->GetSprite(), pTank->GetStateMachine()->GetDirection(), *pTank->GetVector(), color);
}

void World::PrintShell(Tank* pTank)
{
	if (pTank->GetShell() != nullptr)
		m_screenManager.PrintShells(pTank->GetShell()->GetSprite(), pTank->GetShell()->GetDirection(), *pTank->GetShell()->GetPosition());
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
	GoToXY(42, 0);
	std::cout << "+-------------+";
	GoToXY(42, 1);
	std::cout << "| Score: " << m_pPlayer->GetScore() << "\t|";
	GoToXY(42, 2);
	std::cout << "+-------------+";


	GoToXY(42, 4);
	std::cout << "+-------+";
	GoToXY(42, 5);
	std::cout << "| HP: " << m_pPlayer->GetHP() << " |";
	GoToXY(42, 6);
	std::cout << "+-------+";

	GoToXY(42, 8);
	std::cout << "+-------------------+";
	GoToXY(42, 9);
	std::cout << "|    How to Play    |";
	GoToXY(42, 10);
	std::cout << "+-------------------+";
	GoToXY(42, 11);
	std::cout << "| W, A, S, D = Move |";
	GoToXY(42, 12);
	std::cout << "| K = Fire          |";
	GoToXY(42, 13);
	std::cout << "| Q = Exit          |";
	GoToXY(42, 14);
	std::cout << "+-------------------+";
}

void World::DestroyAndGenerateEnemyTank(int index)
{
	m_screenManager.PrintEmptySpace(*m_pEnemy[index]->GetVector());

	delete m_pEnemy[index];
	m_pEnemy[index] = nullptr;
	m_pEnemy[index] = new Enemy();
}

void World::PrintResult()
{
	GoToXY(2, 2);
	std::cout << "+-------------------+";

	GoToXY(2, 3);
	std::cout << "|    Total Score    |";
	
	GoToXY(2, 4);
	std::cout << "+-------------------+";
	
	GoToXY(2, 5);
	std::cout << "|";

	if(m_pPlayer->GetScore() == 0)
		GoToXY(12, 5);
	else
		GoToXY(11, 5);
	std::cout << m_pPlayer->GetScore();
	
	GoToXY(22, 5);
	std::cout << "|";

	GoToXY(2, 6);
	std::cout << "+-------------------+";
	GoToXY(2, 9);

	_getch();
}
