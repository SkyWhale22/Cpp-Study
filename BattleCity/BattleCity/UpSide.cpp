#include "UpSide.h"
#include <Windows.h>

UpSide::UpSide()
{
}


UpSide::~UpSide()
{
}

void UpSide::ReadSprite(char* pName)
{
	TankState::ReadSprite(pName);

	pDir = pTank->FirstChildElement("Up");

	m_sprite = pDir->GetText();
}