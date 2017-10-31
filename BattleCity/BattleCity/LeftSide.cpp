#include "LeftSide.h"



LeftSide::LeftSide()
{
}


LeftSide::~LeftSide()
{
}

void LeftSide::ReadSprite(char* pName)
{
	TankState::ReadSprite(pName);

	pDir = pTank->FirstChildElement("Left");

	m_sprite = pDir->GetText();
}