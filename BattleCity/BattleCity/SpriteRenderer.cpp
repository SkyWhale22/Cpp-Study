#include "SpriteRenderer.h"
#include "Vector2.h"
#include <iostream>

using std::cout;
using std::endl;


std::unordered_map<SpriteRenderer::Color, unsigned char> SpriteRenderer::m_colorMap =
{
	{ SpriteRenderer::Color::kYellow, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY },
	{ SpriteRenderer::Color::kWhite, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY },
	{ SpriteRenderer::Color::kBrown,  FOREGROUND_RED & FOREGROUND_BLUE | BACKGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY },
	{ SpriteRenderer::Color::kSilver, 0x0009 }
};

SpriteRenderer::SpriteRenderer()
{
}


SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Init()
{
	// Get the handle
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Use the handle to get the screen buffer information
	// screen buffer is filled out by the function
	GetConsoleScreenBufferInfo(m_hConsole, &m_screenBuffer);

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(m_hConsole, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(m_hConsole, &cursorInfo);

	// Set the size
	m_windowSize.X = m_screenBuffer.srWindow.Right;
	m_windowSize.Y = m_screenBuffer.srWindow.Bottom;
}

void SpriteRenderer::PrintOnCoord(std::string& sprite, Vector2 pos)
{
	SetCursorPosition(pos);
	DrawSprite(sprite, Color::kWhite);
}

void SpriteRenderer::PrintTanks(std::string & sprite, TankStateMachine::Direction dir, Vector2 pos, Color color)
{
	SetCursorPosition(pos);
	DrawSprite(sprite, color);

	switch (dir)
	{
	case TankStateMachine::Direction::kDown:
		for (int i = 0; i < 3; ++i)
		{
			GoToXY(pos.GetX() + i, pos.GetY() - 1);
			cout << " ";
		}
		break;
	case TankStateMachine::Direction::kUp:
		for (int i = 0; i < 3; ++i)
		{
			GoToXY(pos.GetX() + i, pos.GetY() + 3);
			cout << " ";
		}
		break;
	case TankStateMachine::Direction::kRight:
		for (int i = 0; i < 3; ++i)
		{
			GoToXY(pos.GetX() - 1, pos.GetY() + i);

			cout << " ";
		}
		break;
	case TankStateMachine::Direction::kLeft:
		for (int i = 0; i < 3; ++i)
		{
			GoToXY(pos.GetX() + 3, pos.GetY() + i);
			cout << " ";
		}
		break;
	}
}

void SpriteRenderer::PrintShells(std::string& sprite, CannonShell::MovingDirection dir, Vector2 pos)
{
	SetCursorPosition(pos);
	cout << sprite;

	switch (dir)
	{
	case CannonShell::MovingDirection::kDown:
		for(int i = 0; i < 3; ++i)
			GoToXY(pos.GetX(), pos.GetY() - i);
		cout << " ";
		break;
	case CannonShell::MovingDirection::KUp:
		for (int i = 0; i < 3; ++i)
			GoToXY(pos.GetX(), pos.GetY() + i);
		cout << " ";
		break;
	case CannonShell::MovingDirection::kRight:
		for (int i = 0; i < 3; ++i)
			GoToXY(pos.GetX() - i, pos.GetY());
		cout << " ";
		break;
	case CannonShell::MovingDirection::kLeft:
		for (int i = 0; i < 3; ++i)
			GoToXY(pos.GetX() + i, pos.GetY());
		cout << " ";
		break;
	}
}

void SpriteRenderer::PrintOnInitial(std::string& sprite)
{
	m_pos.X = 0;
	m_pos.Y = 0;
	SetConsoleCursorPosition(m_hConsole, m_pos);

	cout << sprite;
}

void SpriteRenderer::SetCursorPosition(Vector2 pos)
{
	m_pos.X = pos.GetX();
	m_pos.Y = pos.GetY();
	SetConsoleCursorPosition(m_hConsole, m_pos);
}

void SpriteRenderer::DrawSprite(std::string& sprite, Color color)
{
	// Set Color
	SetConsoleTextAttribute(m_hConsole, m_colorMap[color]);

	int spriteSize = sprite.size();

	for (int i = 0; i < spriteSize; ++i)
	{
		cout << sprite[i];

		if (i == 2 || i == 5)
		{
			++m_pos.Y;
			SetConsoleCursorPosition(m_hConsole, m_pos);
		}
	}

	SetConsoleTextAttribute(m_hConsole, m_colorMap[Color::kWhite]);
}

void SpriteRenderer::GoToXY(int x, int y)
{
	m_pos.X = x;
	m_pos.Y = y;
	SetConsoleCursorPosition(m_hConsole, m_pos);
}

void SpriteRenderer::PrintArena(std::string sprite)
{
	int spriteSize = sprite.size();

	if(spriteSize == 38)
	{
		GoToXY(1, 0);
		cout << sprite;
		GoToXY(1, 19);
		cout << sprite;
	}
	else if (spriteSize == 36)
	{
		GoToXY(2, 1);
		cout << sprite;
		GoToXY(2, 18);
		cout << sprite;
	}
	else if (spriteSize == 18)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (i == 0)
				GoToXY(1, 1);
			else
				GoToXY(38, 1);

			for (int j = 0; j < spriteSize; ++j)
			{
				cout << sprite[j];
				++m_pos.Y;
				SetConsoleCursorPosition(m_hConsole, m_pos);
			}
		}
	}
	else if (spriteSize == 16)
	{
		for (int i = 0; i < 2; ++i)
		{
			if(i == 0)
				GoToXY(2, 2);
			else
				GoToXY(37, 2);

			for (int j = 0; j < spriteSize; ++j)
			{
				cout << sprite[j];
				++m_pos.Y;
				SetConsoleCursorPosition(m_hConsole, m_pos);
			}
		}
	}
}

