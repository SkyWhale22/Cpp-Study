#include "CommandMoveRight.h"
#include "Tank.h"

CommandMoveRight::CommandMoveRight()
{
}


void CommandMoveRight::Execute(Tank* pTank)
{
	ChangeDirectionToRight(pTank);
}

void CommandMoveRight::ChangeDirectionToRight(Tank* pTank)
{
	pTank->m_state.ChangeDirection(TankStateMachine::Direction::kRight);
}
