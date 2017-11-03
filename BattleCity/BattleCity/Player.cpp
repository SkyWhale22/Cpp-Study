#include "Player.h"
#include "Macros.h"
#include "Input.h"
#include "Map.h"
#include <conio.h>

Player::Player()
{
	//m_HP = 5;
	SetPosition(13, 7);
	m_state.ChangeDirection(TankStateMachine::Direction::kUp);
	ReadTankSprite();
	SetCommands();
	m_playable = new PC;
}

Player::~Player()
{

}

void Player::Update()
{
	GetInput(m_playable->GetInput());
}

void Player::GetInput(char input)
{
	switch (input)
	{
	case 'w':	// Up
		m_W->Execute(this);
		break;

	case 's':	// Down
		m_S->Execute(this);
		break;

	case 'd':	// Right
		m_D->Execute(this);
		break;

	case 'a':	// Left
		m_A->Execute(this);
		break;

	case 'k':	// Fire
		m_K->Execute(this);
		break;

	case 'q':	// Escape
		m_Q->Execute(this);
		break;

	default:
		break;
	}

	ReadTankSprite();
}

//void Player::AddScore()
//{
//	m_score += 100;
//}

