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

//---------------------------------------------------------------------------------------------------------------------
// Sets enemy type.
//
// Note:
// I didn't use state pattern or strategy pattern on here cus enemy only has two variants.
// Also, these two varients don't have big difference.
// In my opinion, using any kind of pattern on here makes longer code it is harder to read.
//
// If I have to make more variants, I will use strategy pattern.
//---------------------------------------------------------------------------------------------------------------------
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

//---------------------------------------------------------------------------------------------------------------------
// Draws a character depends on type
//---------------------------------------------------------------------------------------------------------------------
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

//---------------------------------------------------------------------------------------------------------------------
// Moves enemy to random direction.
//---------------------------------------------------------------------------------------------------------------------
void Enemy::RandomMove()
{
	int random = rand() % 4;
	
	switch (random)
	{
	case 0:
		Move(0, -1);
		break;
	case 1:
		Move(-1, 0);
		break;
	case 2:
		Move(0, 1);
		break;
	case 3:
		Move(1, 0);
		break;
	}
}

//---------------------------------------------------------------------------------------------------------------------
// Moves enemy depends on its type and the distance between enemy and the player.
//---------------------------------------------------------------------------------------------------------------------
void Enemy::Move(int deltaX, int deltaY)
{
	int index = ((m_y + deltaY) * k_worldWidth) + (m_x + deltaX);
	
	int currentIndex = (m_y * k_worldWidth) + m_x;
	World* pWorldData = World::GetInstance();

	if (IsAtOutSide() == false && m_hitPoints > 0)
	{
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
}

//---------------------------------------------------------------------------------------------------------------------
// Moves enemy
//---------------------------------------------------------------------------------------------------------------------
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