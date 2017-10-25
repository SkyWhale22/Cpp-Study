#include "UpSide.h"

UpSide::UpSide()
{
}


UpSide::~UpSide()
{
}

void UpSide::ReadSprite(char* pName)
{
	TankState::ReadSprite(pName);

	pTank = pType->FirstChildElement(pName);
	pDir = pTank->FirstChildElement("Up");

	m_sprite = pDir->GetText();
}