#include "World.h"
#include "GlobalData.h"
#include "Enemy.h"

Enemy::Enemy(int x, int y)
{
	m_x = x;
	m_y = y;
	m_hitPoints = 1;

	SetType();
}


Enemy::~Enemy()
{
	
}

void Enemy::RandomMove()
{
	int random = (rand() % 4) + 1;

	if (IsDead() == false)
	{
		switch (random)
		{
		case 1:
			Move(0, -1);
			break;
		case 2:
			Move(-1, 0);
			break;
		case 3:
			Move(0, 1);
			break;
		case 4:
			Move(1, 0);
			break;
		}
	}

	int x1 = GetX();
	int y1 = GetY();

	if (x1 < 0 || y1 < 0 || x1 > 19 || y1 > 19)
	{
		Kill();
	}

}

void Enemy::SetType()
{
	int random = rand() % 2;

	switch (random)
	{
	case 0:
		type = EnemyType::k_offensive;
		break;
	case 1:
		type = EnemyType::k_defensive;
		break;
	}
}

void Enemy::Draw()
{
	if (!IsDead())
	{
		switch (type)
		{
		case EnemyType::k_offensive:
			std::cout << "!";
			break;
		case EnemyType::k_defensive:
			std::cout << "?";
			break;
		}
	}
	else
		std::cout << "X";
}

void Enemy::Move(int deltaX, int deltaY)
{
	int x1 = GetX();
	int y1 = GetY();

	if (x1 < 0 || y1 < 0 || x1 > 19 || y1 > 19)
	{
		Kill();
	}

	int index = ((m_y + deltaY) * k_worldWidth) + (m_x + deltaX);
	int currentIndex = (m_y * k_worldWidth) + m_x;
	World* pWorldData = World::GetInstance();

	switch (type)
	{
	case EnemyType::k_offensive:
		if (pWorldData->IsPlayerNear(currentIndex) == true)
		{
			MoveEnemyDependsOnPlayer(pWorldData, 1);
		}
		else
		{
			if (pWorldData->GetTileType(index) == TileType::k_floor)
			{
				Character::Move(deltaX, deltaY);
			}
		}
		break;
	case EnemyType::k_defensive:
		if (pWorldData->IsPlayerNear(currentIndex) == true)
		{
			MoveEnemyDependsOnPlayer(pWorldData, -1);
		}
		else
		{
			if (pWorldData->GetTileType(index) == TileType::k_floor)
			{
				Character::Move(deltaX, deltaY);
			}
		}
		break;
	}
}

void Enemy::MoveEnemyDependsOnPlayer(World* pWorldData, int opposite)
{
	if (pWorldData->m_pPlayer->GetX() > this->m_x && pWorldData->m_pPlayer->GetY() == this->m_y)
	{
		Character::Move(1 * opposite, 0);
	}

	else if (pWorldData->m_pPlayer->GetX() < this->m_x && pWorldData->m_pPlayer->GetY() == this->m_y)
	{
		Character::Move(-1 * opposite, 0);
	}

	else if (pWorldData->m_pPlayer->GetX() == this->m_x && pWorldData->m_pPlayer->GetY() < this->m_y)
	{
		Character::Move(0, -1 * opposite);
	}

	else if (pWorldData->m_pPlayer->GetX() == this->m_x && pWorldData->m_pPlayer->GetY() > this->m_y)
	{
		Character::Move(0, 1 * opposite);
	}
}