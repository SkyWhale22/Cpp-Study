#include "TankState.h"
#include "Tank.h"

void TankState::ReadSprite(char* pName)
{
	doc.LoadFile("SpriteData.xml");	pSprite = doc.RootElement();
	pType = pSprite->FirstChildElement("Tank");
}

void TankState::PrintSprite()
{
	for (int i = 0; i < m_sprite.size(); ++i)
	{
		cout << m_sprite[i];

		if (i == 2 || i == 5)
			cout << endl;
	}
}