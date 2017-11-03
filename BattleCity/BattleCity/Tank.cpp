#include "Tank.h"

#include "TankCommand.h"
#include "CommandMoveUp.h"
#include "CommandMoveDown.h"
#include "CommandMoveRight.h"
#include "CommandMoveLeft.h"
#include "CommandFire.h"
#include "CommandEscape.h"


Tank::~Tank()
{
	delete m_pShells;
	m_pShells = nullptr;

	delete m_playable;
	m_playable = nullptr;

	DeleteCommands();
}

void Tank::SetCommands()
{
	m_W = new CommandMoveUp();
	m_A = new CommandMoveLeft();
	m_S = new CommandMoveDown();
	m_D = new CommandMoveRight();
	m_K = new CommandFire();
	m_Q = new CommandEscape();
}

void Tank::DeleteCommands()
{
	delete m_W; m_W = nullptr;
	delete m_A; m_A = nullptr;
	delete m_S; m_S = nullptr;
	delete m_D; m_D = nullptr;
	delete m_K; m_K = nullptr;
	delete m_Q; m_Q = nullptr;
}

void Tank::SetPosition(int x, int y)
{
	m_position.Set(x, y);
}

void Tank::ReadTankSprite()
{
	m_state.GetState()->ReadSprite("Tank");
}

void Tank::CheckMovingDirection()
{
	switch (m_state.GetDirection())
	{
	case TankStateMachine::Direction::kDown:
		Move(0, 1);
		break;
	case TankStateMachine::Direction::kUp:
		Move(0, -1);
		break;
	case TankStateMachine::Direction::kRight:
		Move(1, 0);
		break;
	case TankStateMachine::Direction::kLeft:
		Move(-1, 0);
		break;
	}
}

void Tank::Move(int x, int y)
{
	int newX = m_position.GetX() + x;
	int newY = m_position.GetY() + y;

	m_position.Set(newX, newY);
}

void Tank::AddScore()
{
	m_playable->AddScore();
}

void Tank::GetDamage()
{
	m_playable->GetDamage();
}

int Tank::GetHP()
{
	return m_playable->GetHP();
}

int Tank::GetScore()
{
	return m_playable->GetScore();
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