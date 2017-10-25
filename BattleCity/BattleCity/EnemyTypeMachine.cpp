#include "EnemyTypeMachine.h"



EnemyTypeMachine::EnemyTypeMachine()
{
}


EnemyTypeMachine::~EnemyTypeMachine()
{
}

//----------------------------------------------------
// Sets tank's type.
//----------------------------------------------------
void EnemyTypeMachine::SetType(Type type)
{
	switch (type)
	{
	case EnemyTypeMachine::Type::kLight:
		m_pType = new LightTank;
		break;
	case EnemyTypeMachine::Type::kHeavy:
		m_pType = new HeavyTank;
		break;
	default:
		break;
	}
}

//----------------------------------------------------
// Prints enemy's sprite on the console.
//----------------------------------------------------
void EnemyTypeMachine::Print()
{
}
