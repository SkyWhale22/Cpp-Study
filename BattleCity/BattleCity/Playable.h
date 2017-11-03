#pragma once
#include "Input.h"
#include "TankStateMachine.h"

class Playable
{
protected:
	int m_score = 0;
	int m_hp = 5;
	Input m_input;

public:
	virtual ~Playable() {}

	virtual void AddScore() = 0;
	virtual int GetScore() = 0;
	virtual char GetInput() = 0;

	void GetDamage() { --m_hp; }
	int GetHP() { return m_hp; }
};

