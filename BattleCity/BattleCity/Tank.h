#pragma once
#include <iostream>
#include <string>
#include "TankStateMachine.h"

using std::cout;
using std::cin;
using std::endl;

class Tank
{
protected:
	int m_HP;
	int m_X;
	int m_Y;

	TankStateMachine m_state;
private:

public:
	virtual ~Tank() {};

	virtual void PrintTank() = 0;
	virtual void Move() = 0;
	virtual void Action() = 0;
	virtual void Update() = 0;
};

