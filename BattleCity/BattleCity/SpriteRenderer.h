#pragma once

#include <Windows.h>
#include <string>
#include <unordered_map>
#include "TankStateMachine.h"
#include "CannonShell.h"

class Vector2;
typedef std::string(*MapPrinter2)();

class SpriteRenderer
{
public:
	enum class Color
	{
		kYellow,
		kWhite,
		kBrown,
		kSilver
	};

private:
	CONSOLE_SCREEN_BUFFER_INFO m_screenBuffer;
	HANDLE m_hConsole;

	COORD m_windowSize;
	COORD m_pos;
	static std::unordered_map<Color, unsigned char> m_colorMap;

public:
	SpriteRenderer();
	~SpriteRenderer();

	void Init();
	
	void PrintTanks(std::string& sprite, TankStateMachine::Direction dir,  Vector2 pos, Color color);
	void PrintShells(std::string& sprite, CannonShell::MovingDirection dir, Vector2 pos);
	
	
	
	void DrawSprite(std::string& sprite, Color color);
	
	void PrintOnCoord(std::string& sprite, Vector2 pos);
	void PrintOnInitial(std::string& sprite);
	void SetCursorPosition(Vector2 pos);


	void GoToXY(int x, int y);
	void PrintArena(std::string sprite);
};

