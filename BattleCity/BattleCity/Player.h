#pragma once
#include "Tank.h"

class Player : public Tank
{
private:
	//int m_score = 0;
	//int m_HP = 5;

public:
	Player();
	~Player();

	virtual void Update() override;
	virtual void ResetDirection() override {};

	void GetInput(char input);

	//int GetScore() { return m_score; }
	//void GetDamage() { --m_HP; }
	//int GetHP() { return m_HP; }
};


