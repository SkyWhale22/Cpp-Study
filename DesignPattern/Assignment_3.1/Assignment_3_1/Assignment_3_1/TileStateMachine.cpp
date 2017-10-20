#include "TileStateMachine.h"

#include "HiddenState.h"
#include "RevealedState.h"
#include "ExploadedState.h"

TileStateMachine::TileStateMachine()
	: m_isExploaded(false)
{
}

TileStateMachine::~TileStateMachine()
{
	delete m_pState;
	m_pState = nullptr;
}

void TileStateMachine::ChangeState(State newState)
{
	if (m_pState != nullptr)
	{
		delete m_pState;
		m_pState = nullptr;
	}

	switch (newState)
	{
	case TileStateMachine::State::kHidden:
		m_pState = new HiddenState();
		break;
	case TileStateMachine::State::kRevealed:
		m_pState = new RevealedState();
		break;
	case TileStateMachine::State::kExploaded:
		m_pState = new ExploadedState();
		m_isExploaded = true;
		break;
	default:
		break;
	}
}

void TileStateMachine::PrintTile()
{
	m_pState->PrintTile();
}
