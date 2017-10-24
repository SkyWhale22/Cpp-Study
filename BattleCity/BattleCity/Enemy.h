#pragma once
#include "Tank.h"
class Enemy :
	public Tank
{
public:
	Enemy();
	~Enemy();

	void PrintTank() override;
	void Move() override;
	void Action() override;
};

