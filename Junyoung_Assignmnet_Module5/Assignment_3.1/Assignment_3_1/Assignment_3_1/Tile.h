// Tile.h
#ifndef __TILE_H__
#define __TILE_H__
#include <iostream>
#include "Character.h"
#include "GlobalData.h"
class Tile
{
protected:
	typedef std::pair<int, int> DamageRange;

public:
	bool isDetected = false;
    virtual ~Tile() { }  // if your class is being used as a base class, it's best to have a virtual destructor
	virtual void Draw() = 0;
	virtual void OnEnter(Character* pCharacter) { }
	virtual void SetState() {}
	
	bool IsExploded() { return isDetected; };

	void GiveDamage(Character* pPlayer, DamageRange range)
	{
		int damage = (rand() % (range.second - range.first)) + range.first;
		pPlayer->Damage(damage);
	}
	TileType type;
};

#endif

