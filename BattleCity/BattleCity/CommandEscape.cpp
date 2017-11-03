#include "CommandEscape.h"
#include "Tank.h"

CommandEscape::CommandEscape()
{
}

void CommandEscape::Execute(Tank* pTank)
{
	Escape(pTank);
}

void CommandEscape::Escape(Tank* pTank)
{
	pTank->m_escapeFlag = true;
}
