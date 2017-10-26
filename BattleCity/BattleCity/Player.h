#pragma once
#include "Tank.h"

class Input;

class Player :
	public Tank
{
private:
	Input* m_pInput;

public:
	Player();
	~Player();

	void PrintTank() override;
	void Move(int x, int y) override;
	void Action() override;
	bool Update() override;

	void ReadSprite();
	bool CheckMovable();
};


