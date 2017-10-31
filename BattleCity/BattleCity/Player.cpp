#include "Player.h"
#include "Macros.h"
#include "Input.h"
#include "Map.h"
#include <conio.h>

Player::Player()
{
	m_HP = 5;
	m_position.Set(15, 14);
	m_state.ChangeDirection(TankStateMachine::Direction::kUp);
	ReadTankSprite();
}

Player::~Player()
{
}

void Player::GetInput(char input)
{

	switch (input)
	{
	case 'w':	// Up
		m_state.ChangeDirection(TankStateMachine::Direction::kUp);

		//for (int i = 0; i < 3; ++i)
		//{
		//	if (m_shells[i].GetState() == CannonShell::State::kResting)
		//	{
		//		m_shells[i].SetDirection(CannonShell::MovingDirection::KUp);

		//		//     #P#
		//		//     #O#
		//		//     # #
		//		m_shells[i].SetPosition(m_position.GetX() + 1, m_position.GetY());
		//	}
		//}
		break;

	case 's':	// Down
		m_state.ChangeDirection(TankStateMachine::Direction::kDown);

		//for (int i = 0; i < 3; ++i)
		//{
		//	if (m_shells[i].GetState() == CannonShell::State::kResting)
		//	{
		//		m_shells[i].SetDirection(CannonShell::MovingDirection::kDown);
		//		
		//		//     # #
		//		//     #O#
		//		//     #P#
		//		m_shells[i].SetPosition(m_position.GetX() + 1, m_position.GetY() + 2);
		//	}
		//}
		break;

	case 'd':	// Right
		m_state.ChangeDirection(TankStateMachine::Direction::kRight);

		//for (int i = 0; i < 3; ++i)
		//{
		//	if (m_shells[i].GetState() == CannonShell::State::kResting)
		//	{
		//		m_shells[i].SetDirection(CannonShell::MovingDirection::kRight);

		//		//     ###
		//		//      OP
		//		//     ###
		//		m_shells[i].SetPosition(m_position.GetX() + 2, m_position.GetY() + 1);
		//	}
		//}
		break;

	case 'a':	// Left
		m_state.ChangeDirection(TankStateMachine::Direction::kLeft);

		//for (int i = 0; i < 3; ++i)
		//{
		//	if (m_shells[i].GetState() == CannonShell::State::kResting)
		//	{
		//		m_shells[i].SetDirection(CannonShell::MovingDirection::kLeft);
		//		
		//		//     ###
		//		//     PO
		//		//     ###
		//		m_shells[i].SetPosition(m_position.GetX(), m_position.GetY() + 1);
		//	}
		//}
		break;
		
	case 'k':
		Shoot();
		break;

	default:
		break;
	}

	ReadTankSprite();
}


bool Player::CheckMovable()
{
	return false;
}

