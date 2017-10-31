#include "DownSide.h"
#include "Macros.h"


DownSide::DownSide()
{
}


DownSide::~DownSide()
{
}

void DownSide::ReadSprite(char* pName)
{
	TankState::ReadSprite(pName);

	pDir = pTank->FirstChildElement("Down");

	m_sprite = pDir->GetText();
}
