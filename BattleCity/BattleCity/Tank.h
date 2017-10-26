#pragma once
#include <iostream>
#include <string>
#include "TankStateMachine.h"
#include "Vector2.h"

using std::cout;
using std::cin;
using std::endl;

class Vector2;

class Tank
{
protected:
	int m_HP;
	Vector2 m_position;

	TankStateMachine m_state;
public:
	virtual ~Tank() {};

	virtual void PrintTank() = 0;
	virtual void Move(int x, int y) = 0;
	virtual void Action() = 0;
	virtual bool Update() = 0;

	TankStateMachine* GetStateMachine() { return &m_state; };
	
	Vector2* GetVector();
};