#include "TankState.h"
#include "World.h"

void TankState::ReadSprite(char* pName)
{
	doc.LoadFile("SpriteData.xml");
	pSprite = doc.RootElement();
	pTank = pSprite->FirstChildElement("Tank");
}