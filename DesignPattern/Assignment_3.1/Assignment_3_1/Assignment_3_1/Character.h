#pragma once
class Character
{
protected:
	int m_x;
	int m_y;
	int m_hitPoints;

public:
	bool isOutSide = false;

	virtual ~Character() {};

	virtual bool IsDead() = 0;
	virtual void Move(int deltaX, int deltaY);
	virtual void Draw() = 0;  // assumes the cursor is at the right place
	
	bool IsAtOutSide();

	int GetX() { return m_x; }
	int GetY() { return m_y; }

	void Kill() { m_hitPoints = 0; }
	
	void Damage(int amount);
};