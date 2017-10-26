#include "TankState.h"
#include "Tank.h"
#include "World.h"
#include "SpriteRenderer.h"

void TankState::ReadSprite(char* pName)
{
	doc.LoadFile("SpriteData.xml");	pSprite = doc.RootElement();
	pType = pSprite->FirstChildElement("Tank");
}

void TankState::PrintSprite(int posX, int posY)
{
	CONSOLE_SCREEN_BUFFER_INFO screenBuffer;
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &screenBuffer);

	COORD pos;
	pos.X = posX;
	pos.Y = posY;
	SetConsoleCursorPosition(hConsole, pos);

	int spriteSize = m_sprite.size();

	for (int i = 0; i < spriteSize; ++i)
	{
		cout << m_sprite[i];

		if (i == 2 || i == 5)
		{
			cout << endl;
			++pos.Y;
			SetConsoleCursorPosition(hConsole, pos);
		}
	}
}