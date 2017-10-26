#pragma once
class Vector2
{
private:
	int posX;
	int posY;

public:
	Vector2();
	~Vector2();

	int GetX() { return posX; }
	int GetY() { return posY; }

	Vector2* GetPosition() { return this; }

	void Set(int x, int y);
};

