// FloorTile.h
#ifndef __FLOORTILE_H__
#define __FLOORTILE_H__

#include "Tile.h"

class FloorTile : public Tile
{
public:
	FloorTile() { type = TileType::k_floor; }
	virtual void Draw() override;
};

#endif
