#pragma once
#include "EnemyType.h"
class HeavyTank :
	public EnemyType
{
public:
	HeavyTank();
	~HeavyTank();

	void PrintEnemy() override;
	void EnemyAction() override;
};

