#pragma once
#include "Tank.h"
class Player :
	public Tank
{
public:
	Player();
	~Player();

	void PrintTank() override;
	void Move() override;
	void Action() override;
};

