#pragma once

#include <Windows.h>
#include <string>
#include <unordered_map>

class Vector2;

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
	void DrawSprite(std::string& sprite, Vector2 pos);
	void PrintOnCoord(std::string& sprite, Vector2 pos);
	void SetCursorPosition(Vector2 pos);
};

