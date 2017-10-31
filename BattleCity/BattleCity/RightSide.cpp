#include "RightSide.h"



RightSide::RightSide()
{
}


RightSide::~RightSide()
{
}

void RightSide::ReadSprite(char* pName)
{
	TankState::ReadSprite(pName);

	pDir = pTank->FirstChildElement("Right");

	m_sprite = pDir->GetText();
}