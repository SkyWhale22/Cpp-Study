#pragma once
#include "EnemyType.h"
class LightTank :
	public EnemyType
{
public:
	LightTank();
	~LightTank();

	void PrintEnemy() override;
	void EnemyAction() override;
};

