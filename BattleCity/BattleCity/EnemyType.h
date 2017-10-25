#pragma once

#include <iostream>
using std::cout;
using std::endl;

class EnemyTypeMachine;

class EnemyType
{
public:

	virtual void PrintEnemy() = 0;
	virtual void EnemyAction() = 0;

protected:
	EnemyTypeMachine* m_pTypeMachine;
};

