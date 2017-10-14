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
	~Enemy();

	void SetType();
	void Draw() override;
	bool IsDead() override { return (m_hitPoints <= 0); }
	void Move(int deltaX, int deltaY) override;
	void MoveEnemyDependsOnPlayer(World* pWorldData, int opposite);

};
