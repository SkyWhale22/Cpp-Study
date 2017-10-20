#pragma once
#include "Character.h"
#include "GlobalData.h"
#include <iostream>
class World;

class Enemy : public Character
{
	enum class EnemyType
	{
		k_offensive,
		k_defensive
	}type;

public:
	Enemy(int x, int y);

	virtual void Draw() override;
	virtual bool IsDead() override { return (m_hitPoints <= 0); }
	virtual void Move(int deltaX, int deltaY) override;
	
	void RandomMove();
	void SetType();
	void MoveEnemyDependsOnPlayer(World* pWorldData, int opposite);

};
