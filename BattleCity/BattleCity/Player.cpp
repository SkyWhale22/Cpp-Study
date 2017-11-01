#include "Player.h"
#include "Macros.h"
#include "Input.h"
#include "Map.h"
#include <conio.h>

Player::Player()
{
	m_HP = 5;
	SetPosition(13, 7);
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
		break;

	case 's':	// Down
		m_state.ChangeDirection(TankStateMachine::Direction::kDown);
		break;

	case 'd':	// Right
		m_state.ChangeDirection(TankStateMachine::Direction::kRight);
		break;

	case 'a':	// Left
		m_state.ChangeDirection(TankStateMachine::Direction::kLeft);
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

void Player::AddScore()
{
	m_score += 100;
}

