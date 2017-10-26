#pragma once
#include "Tank.h"
class Enemy :
	public Tank
{
public:
	Enemy();
	~Enemy();

	void PrintTank() override;
	void Move(int x, int y) override;
	void Action() override;
};

