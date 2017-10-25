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

	pTank = pType->FirstChildElement(pName);
	pDir = pTank->FirstChildElement("Right");

	m_sprite = pDir->GetText();
}