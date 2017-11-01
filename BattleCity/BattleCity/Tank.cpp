#include "Tank.h"

Tank::~Tank()
{
	delete m_pShells;
	m_pShells = nullptr;
}


void Tank::SetPosition(int x, int y)
{
	m_position.Set(x, y);
}

void Tank::ReadTankSprite()
{
	m_state.GetState()->ReadSprite("Tank");
}

void Tank::Move(int x, int y)
{
	int newX = m_position.GetX() + x;
	int newY = m_position.GetY() + y;

	m_position.Set(newX, newY);
}

void Tank::Shoot()
{
	if (m_pShells == nullptr)
	{
		m_pShells = new CannonShell();

		switch (m_state.GetDirection())
		{
		case TankStateMachine::Direction::kUp:
			m_pShells->SetDirection(CannonShell::MovingDirection::KUp, m_position);
			break;
		case TankStateMachine::Direction::kDown:
			m_pShells->SetDirection(CannonShell::MovingDirection::kDown, m_position);
			break;
		case TankStateMachine::Direction::kRight:
			m_pShells->SetDirection(CannonShell::MovingDirection::kRight, m_position);
			break;
		case TankStateMachine::Direction::kLeft:
			m_pShells->SetDirection(CannonShell::MovingDirection::kLeft, m_position);
			break;
		default:
			break;
		}
		--m_shootCount;
	}

}

void Tank::MoveAllShells()
{
	m_pShells->Move();
}

void Tank::DeleteShell()
{
	delete m_pShells;
	m_pShells = nullptr;
}