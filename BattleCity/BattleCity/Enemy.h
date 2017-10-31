#pragma once
#include "Tank.h"

class Enemy :
	public Tank
{
private:
	int m_timeToMove;
public:
	Enemy();
	~Enemy();

	void MoveEnemyTank();
	void HowManyTimesToMove();
	void SetEnemyStatus();
};

