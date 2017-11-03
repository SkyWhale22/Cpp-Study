#include "CommandMoveDown.h"
#include "Tank.h"



CommandMoveDown::CommandMoveDown()
{
}

void CommandMoveDown::Execute(Tank* pTank)
{
	ChangeToDirectionToDown(pTank);
}

void CommandMoveDown::ChangeToDirectionToDown(Tank* pTank)
{
	pTank->m_state.ChangeDirection(TankStateMachine::Direction::kDown);
}
