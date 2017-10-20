#include "Character.h"
#include "GlobalData.h"

void Character::Move(int deltaX, int deltaY)
{
	m_x += deltaX;
	m_y += deltaY;
}

bool Character::IsAtOutSide()
{
	if (m_x < 0 || m_y < 0 || m_x >= k_worldWidth || m_y >= k_worldHeight)
	{
		isOutSide = true;
		Kill();
	}

	return isOutSide;
}

void Character::Damage(int amount)
{
	m_hitPoints -= amount;

	if (m_hitPoints < 0)
		m_hitPoints = 0;
}