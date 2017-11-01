#include "Enemy.h"

Enemy::Enemy()
{
	SetRandomPosition();
	HowManyTimesToMove();

	ReadTankSprite();
}


Enemy::~Enemy()
{
}

void Enemy::SetEnemyStatus()
{
	int index = rand() % 3;
	bool attackOrNot = (rand() % 10 <= 3) ? true : false;

	switch (m_state.GetDirection())
	{
	case TankStateMachine::Direction::kDown:
		switch (index)
		{
		case 0: // UpSide
			m_state.ChangeDirection(TankStateMachine::Direction::kUp);
			break;
		case 1: // RightSide
			m_state.ChangeDirection(TankStateMachine::Direction::kRight);
			break;
		case 2: // LeftSide
			m_state.ChangeDirection(TankStateMachine::Direction::kLeft);
			break;
		}
		break;
	case TankStateMachine::Direction::kUp:
		switch (index)
		{
		case 0: // DownSide
			m_state.ChangeDirection(TankStateMachine::Direction::kDown);
			break;
		case 1: // RightSide
			m_state.ChangeDirection(TankStateMachine::Direction::kRight);
			break;
		case 2: // LeftSide
			m_state.ChangeDirection(TankStateMachine::Direction::kLeft);
			break;
		}
		break;
	case TankStateMachine::Direction::kRight:
		switch (index)
		{
		case 0: // DownSide
			m_state.ChangeDirection(TankStateMachine::Direction::kDown);
			break;
		case 1: // UpSide
			m_state.ChangeDirection(TankStateMachine::Direction::kUp);
			break;
		case 2: // LeftSide
			m_state.ChangeDirection(TankStateMachine::Direction::kLeft);
			break;
		}
		break;
	case TankStateMachine::Direction::kLeft:
		switch (index)
		{
		case 0: // DownSide
			m_state.ChangeDirection(TankStateMachine::Direction::kDown);
			break;
		case 1: // UpSide
			m_state.ChangeDirection(TankStateMachine::Direction::kUp);
			break;
		case 2: // RightSide
			m_state.ChangeDirection(TankStateMachine::Direction::kRight);
			break;
		}
		break;
	}

	if (attackOrNot)
		Shoot();

	ReadTankSprite();
}

void Enemy::SetRandomPosition()
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
		SetEnemyStatus();
		HowManyTimesToMove();
	}
}

void Enemy::HowManyTimesToMove()
{
	m_timeToMove = (rand() % 2) + 5;
}

