#pragma once
#include "Vector2.h"
#include "tinyxml2.h"
#include <string>

class CannonShell
{
public:
	enum class MovingDirection
	{
		kLeft,
		kRight,
		KUp,
		kDown
	};

private:
	Vector2 m_position;
	std::string m_sprite;

	MovingDirection m_dir;

public:

	CannonShell();
	~CannonShell();

	void SetPosition(int x, int y);

	void SetDirection(MovingDirection dir, Vector2& pos);
	void Move();
	void ReadShellSprite();
	

	std::string GetDirString();

	std::string& GetSprite() { return m_sprite; }
	MovingDirection GetDirection() { return m_dir; }
	Vector2* GetPosition() { return &m_position; }
};

