// MimicTile.h
#ifndef __MIMICTILE_H__
#define __MIMICTILE_H__

#include "Tile.h"
#include <utility>

class MimicTile : public Tile
{
	class MimicState* m_pHidden;
	class MimicState* m_pRevealed;
	class MimicState* m_pExploded;

	class MimicState* m_pState;


	static const DamageRange s_damageRange;

public:
    MimicTile();
	~MimicTile();
	MimicState* GetHiddenState() { return m_pHidden; }
	MimicState* GetRevealedState() { return m_pRevealed; }
	MimicState* GetExplodedState() { return m_pExploded; }
	MimicState* GetCurrentState() { return m_pState; }

	void SetState(MimicState* pState) { m_pState = pState; }
    virtual void Draw() override;
    virtual void OnEnter(Character* pCharacter) override;
};

class MimicState
{
public:
	virtual ~MimicState() {}
	virtual void PrintTile() {}
	//void(*StateMachine)(MimicTile*);
};

class StateHidden : public MimicState
{
public:
	StateHidden() {}
	~StateHidden() {}

	void PrintTile()
	{
		std::cout << "$";
	}
};

class StateRevealed : public MimicState
{
public:
	StateRevealed() {}
	~StateRevealed() {}

	void PrintTile()
	{
		std::cout << "*";
	}
};

class StateExploded : public MimicState
{
public :
	StateExploded() {}
	~StateExploded() {}

	void PrintTile()
	{
		std::cout << "#";
	}
};
#endif

