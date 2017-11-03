#include "CommandFire.h"
#include "Tank.h"

CommandFire::CommandFire()
{
}


void CommandFire::Execute(Tank* pTank)
{
	Fire(pTank);
}

void CommandFire::Fire(Tank* pTank)
{
	if (pTank->m_pShells == nullptr)
	{
		pTank->m_pShells = new CannonShell();

		switch (pTank->m_state.GetDirection())
		{
		case TankStateMachine::Direction::kUp:
			pTank->m_pShells->SetDirection(CannonShell::MovingDirection::KUp, pTank->m_position);
			break;
		case TankStateMachine::Direction::kDown:
			pTank->m_pShells->SetDirection(CannonShell::MovingDirection::kDown, pTank->m_position);
			break;
		case TankStateMachine::Direction::kRight:
			pTank->m_pShells->SetDirection(CannonShell::MovingDirection::kRight, pTank->m_position);
			break;
		case TankStateMachine::Direction::kLeft:
			pTank->m_pShells->SetDirection(CannonShell::MovingDirection::kLeft, pTank->m_position);
			break;
		default:
			break;
		}
		--pTank->m_shootCount;
	}

}
