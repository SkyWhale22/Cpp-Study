#pragma once
#include <iostream>
#include <string>
#include "TankStateMachine.h"
#include "Vector2.h"
#include "CannonShell.h"

using std::cout;
using std::cin;
using std::endl;

class Vector2;

class Tank
{

private:
	Vector2 m_position;
	CannonShell* m_pShells;

protected:
	int m_HP;
	TankStateMachine m_state;
	CannonShell::MovingDirection m_shellDir;

public:
	int m_shootCount = 2;
	virtual ~Tank();

	void SetPosition(int x, int y);
	void ReadTankSprite();
	void Move(int x, int y);
	
	void Shoot();
	void MoveAllShells();
	void DeleteShell();
	void IncreaseShootCount() { ++m_shootCount; }
	TankStateMachine* GetStateMachine() { return &m_state; };
	
	Vector2* GetVector() { return &m_position; }

	CannonShell* GetShell() { return m_pShells; }
};