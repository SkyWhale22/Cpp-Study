// Tile.h
#ifndef __TILE_H__
#define __TILE_H__
#include <iostream>
#include "Character.h"
#include "GlobalData.h"

class Tile
{
public:
    virtual ~Tile() { }  // if your class is being used as a base class, it's best to have a virtual destructor
	virtual void Draw() = 0;
	virtual void OnEnter(Character* pCharacter) { }
	
	TileType type;
};

#endif

