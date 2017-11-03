#include "CommandMoveUp.h"
#include "Tank.h"


CommandMoveUp::CommandMoveUp()
{
}

void CommandMoveUp::Execute(Tank* pTank)
{
	ChangeDirectionToUp(pTank);
}
void CommandMoveUp::ChangeDirectionToUp(Tank* pTank)
{
	pTank->m_state.ChangeDirection(TankStateMachine::Direction::kUp);
}
