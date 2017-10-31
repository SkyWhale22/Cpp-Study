#include "TankStateMachine.h"
#include <string>

#include "UpSide.h"
#include "DownSide.h"
#include "LeftSide.h"
#include "RightSide.h"

TankStateMachine::TankStateMachine()
{
}

TankStateMachine::~TankStateMachine()
{
	DestroyState();
}

void TankStateMachine::ChangeDirection(Direction newDir)
{
	if (m_pState != nullptr)
		DestroyState();

	switch (newDir)
	{
	case TankStateMachine::Direction::kUp:
		m_pState = new UpSide();
		break;
	case TankStateMachine::Direction::kDown:
		m_pState = new DownSide();
		break;
	case TankStateMachine::Direction::kRight:
		m_pState = new RightSide();
		break;
	case TankStateMachine::Direction::kLeft:
		m_pState = new LeftSide();
		break;
	default:
		break;
	}

	m_dir = newDir;
}

void TankStateMachine::PrintSprite(char* pName)
{
	m_pState->ReadSprite(pName);
}

void TankStateMachine::DestroyState()
{
	delete m_pState;
	m_pState = nullptr;
}
