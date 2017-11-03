#pragma once
#include <iostream>
#include <string>

#include "TankStateMachine.h"
#include "TankCommand.h"

#include "Playable.h"
#include "PC.h"
#include "NPC.h"

#include "Vector2.h"
#include "CannonShell.h"

using std::cout;
using std::cin;
using std::endl;

class Vector2;
class TankCommand;

class Tank
{
	friend class CommandMoveRight;
	friend class CommandMoveLeft;
	friend class CommandMoveUp;
	friend class CommandMoveDown;
	friend class CommandFire;
	friend class CommandEscape;	

private:
	Vector2 m_position;
	CannonShell* m_pShells;

	bool m_escapeFlag = false;

protected:
	Tank* pTank;
	//int m_HP;
	int m_shootCount = 2;

	TankCommand* m_A;
	TankCommand* m_S;
	TankCommand* m_D;
	TankCommand* m_W;
	TankCommand* m_K;
	TankCommand* m_Q;

	TankStateMachine m_state;
	CannonShell::MovingDirection m_shellDir;
	Playable* m_playable;
	
	void SetPosition(int x, int y);
	void ReadTankSprite();
public:
	virtual ~Tank();

	virtual void Update() = 0;
	virtual void ResetDirection() = 0;

	void SetCommands();
	void DeleteCommands();

	bool CheckToEscape() { return m_escapeFlag; }

	void CheckMovingDirection();
	void Move(int x, int y);
	void AddScore();
	void GetDamage();
	int GetHP();
	int GetScore();

	void MoveAllShells();
	void DeleteShell();
	void IncreaseShootCount() { ++m_shootCount; }

	TankStateMachine* GetStateMachine() { return &m_state; };
	
	Vector2* GetVector() { return &m_position; }

	CannonShell* GetShell() { return m_pShells; }
};