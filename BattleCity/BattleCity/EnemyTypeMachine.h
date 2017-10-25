#pragma once

#include "EnemyType.h"
#include "LightTank.h"
#include "HeavyTank.h"

class EnemyTypeMachine
{
public:
	enum class Type
	{
		kLight,
		kHeavy,

		NUM_Types
	};

	EnemyTypeMachine();
	~EnemyTypeMachine();

	void SetType(Type type);
	void Print();

private:
	EnemyType* m_pType;

public:
	EnemyType* GetType() { return m_pType; }

};

