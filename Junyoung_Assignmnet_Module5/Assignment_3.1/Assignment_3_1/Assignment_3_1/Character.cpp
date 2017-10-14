#include "Character.h"

void Character::Move(int deltaX, int deltaY)
{
	m_x += deltaX;
	m_y += deltaY;
}

void Character::Damage(int amount)
{
	m_hitPoints -= amount;

	if (m_hitPoints < 0)
		m_hitPoints = 0;
}