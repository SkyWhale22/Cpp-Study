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
	void Move() override;
	void Action() override;
	void Update() override;
};

