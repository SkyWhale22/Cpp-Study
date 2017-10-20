#include "TileStateMachine.h"

#include "HiddenState.h"
#include "RevealedState.h"
#include "ExploadedState.h"

TileStateMachine::TileStateMachine()
	: m_isExploaded(false)
{
}

//---------------------------------------------------------------------------------------------------------------------
// Always Deallocate memory of state. It leaks hella a lot of memories. 
//---------------------------------------------------------------------------------------------------------------------
TileStateMachine::~TileStateMachine()
{
	delete m_pState;
	m_pState = nullptr;
}

//---------------------------------------------------------------------------------------------------------------------
//  Changes state.
//---------------------------------------------------------------------------------------------------------------------
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

//---------------------------------------------------------------------------------------------------------------------
// Prints a character depend on state 
//---------------------------------------------------------------------------------------------------------------------
void TileStateMachine::PrintTile()
{
	m_pState->PrintTile();
}
