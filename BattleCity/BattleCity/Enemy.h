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

	virtual void Update() override;
	virtual void ResetDirection() override;

	void Reset();
	void MoveEnemyTank();
	void HowManyTimesToMove();
	//void SetEnemyStatus();

	void SetInitDirection();
};

