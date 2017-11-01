#pragma once
#include "Tank.h"

class Player : public Tank
{
private:
	int m_score = 0;
	int m_HP = 5;

public:
	Player();
	~Player();

	void GetInput(char input);
	bool CheckMovable();

	void AddScore();

	int GetScore() { return m_score; }
	void GetDamage() { --m_HP; }
	int GetHP() { return m_HP; }
};


