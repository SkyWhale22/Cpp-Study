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
	{ SpriteRenderer::Color::kSilver, FOREGROUND_RED }
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
	m_pos.X = pos.GetX();
	m_pos.Y = pos.GetY();

	SetConsoleCursorPosition(m_hConsole, m_pos);

	DrawSprite(sprite, pos);

	SetConsoleCursorPosition(m_hConsole, m_pos);
}

void SpriteRenderer::SetCursorPosition(Vector2 pos)
{
	m_pos.X = pos.GetX();
	m_pos.Y = pos.GetY();
	SetConsoleCursorPosition(m_hConsole, m_pos);
}

void SpriteRenderer::DrawSprite(std::string& sprite, Vector2 pos)
{
	// Set Color
	SetConsoleTextAttribute(m_hConsole, m_colorMap[Color::kYellow]);

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

