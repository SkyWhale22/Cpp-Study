#include "Enemy.h"

Enemy::Enemy()
{
	SetInitDirection();
	HowManyTimesToMove();

	ReadTankSprite();
	SetCommands();
	m_playable = new NPC;
}


Enemy::~Enemy()
{
}

void Enemy::Update()
{
	MoveEnemyTank();
}

void Enemy::ResetDirection()
{
	Reset();
}

void Enemy::Reset()
{
	int index = rand() % 3;

	switch (m_state.GetDirection())
	{
	case TankStateMachine::Direction::kDown:
		switch (index)
		{
		case 0: // UpSide
			m_W->Execute(this);
			break;
		case 1: // RightSide
			m_D->Execute(this);
			break;
		case 2: // LeftSide
			m_A->Execute(this);
			break;
		}
		break;
	case TankStateMachine::Direction::kUp:
		switch (index)
		{
		case 0: // DownSide
			m_S->Execute(this);
			break;
		case 1: // RightSide
			m_D->Execute(this);
			break;
		case 2: // LeftSide
			m_A->Execute(this);
			break;
		}
		break;
	case TankStateMachine::Direction::kRight:
		switch (index)
		{
		case 0: // DownSide
			m_S->Execute(this);
			break;
		case 1: // UpSide
			m_W->Execute(this);
			break;
		case 2: // LeftSide
			m_A->Execute(this);
			break;
		}
		break;
	case TankStateMachine::Direction::kLeft:
		switch (index)
		{
		case 0: // DownSide
			m_S->Execute(this);
			break;
		case 1: // UpSide
			m_W->Execute(this);
			break;
		case 2: // RightSide
			m_D->Execute(this);
			break;
		}
		break;
	}

	ReadTankSprite();
}

void Enemy::SetInitDirection()
{
	int random = rand() % 4;

	switch (random)
	{
	case 0:
		SetPosition(4, 3);
		m_state.ChangeDirection(TankStateMachine::Direction::kDown);
		break;
	case 1:
		SetPosition(33, 3);
		m_state.ChangeDirection(TankStateMachine::Direction::kLeft);
		break;
	case 2:
		SetPosition(4, 14);
		m_state.ChangeDirection(TankStateMachine::Direction::kRight);
		break;
	case 3:
		SetPosition(33, 14);
		m_state.ChangeDirection(TankStateMachine::Direction::kUp);
		break;
	default:
		break;
	}
}

void Enemy::MoveEnemyTank()
{
	bool attackOrNot = (rand() % 10 <= 3) ? true : false;

	if (m_timeToMove > 0)
	{
		switch (m_state.GetDirection())
		{
		case TankStateMachine::Direction::kDown: // DownSide
			Move(0, 1);
			--m_timeToMove;
			break;
		case TankStateMachine::Direction::kUp: // UpSide
			Move(0, -1);
			--m_timeToMove;
				break;
		case TankStateMachine::Direction::kRight: // RightSide
			Move(1, 0);
			--m_timeToMove;
			break;
		case TankStateMachine::Direction::kLeft: // LeftSide
			Move(-1, 0);
			--m_timeToMove;
			break;
		}
	}
	else if (m_timeToMove <= 0)
	{
		//SetEnemyStatus();

		Reset();
		HowManyTimesToMove();
	}

	if (attackOrNot)
		 m_K->Execute(this);
}

void Enemy::HowManyTimesToMove()
{
	m_timeToMove = (rand() % 2) + 5;
}

