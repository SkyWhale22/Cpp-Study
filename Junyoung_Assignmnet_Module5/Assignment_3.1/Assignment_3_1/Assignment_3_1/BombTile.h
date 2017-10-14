// BombTile.h
#ifndef __BOMBTILE_H__
#define __BOMBTILE_H__

#include "Tile.h"
#include <utility>

class BombTile : public Tile
{
	// Q : What is the better way for state machine?
	class BombState* m_pActive;
	class BombState* m_pDead;
	class BombState* m_pState;

	static const DamageRange s_damageRange;

	BombState* GetActiveState() { return m_pActive; }
	BombState* GetDeadState() { return m_pDead; }

public:
    BombTile();
	~BombTile();
	void SetState(BombState* pState) { m_pState = pState; }
    virtual void Draw() override;
    virtual void OnEnter(Character* pPlayer) override;
};

class BombState
{
public:
	virtual ~BombState() {}
	virtual void PrintTile() {}
};

class StateActive : public BombState
{
public:
	StateActive() {}
	~StateActive() {}

	void PrintTile() 
	{
		std::cout << "*";
	}
};

class StateDead : public BombState
{
public:
	StateDead() {}
	~StateDead() {}

	void PrintTile()
	{
		std::cout << "#";
	}
};

#endif

