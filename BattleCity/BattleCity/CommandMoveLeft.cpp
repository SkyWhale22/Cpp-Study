#include "CommandMoveLeft.h"
#include "Tank.h"



CommandMoveLeft::CommandMoveLeft()
{
}

void CommandMoveLeft::Execute(Tank* pTank)
{
	ChangeDirectionToLeft(pTank);
}

void CommandMoveLeft::ChangeDirectionToLeft(Tank* pTank)
{
	pTank->m_state.ChangeDirection(TankStateMachine::Direction::kLeft);
}
