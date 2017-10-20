// EndTile.h
#ifndef __ENDTILE_H__
#define __ENDTILE_H__

#include "Tile.h"
#include "World.h"

class EndTile : public Tile
{
	
public:
	EndTile();
	~EndTile() {};
    virtual void Draw() override;
    virtual void OnEnter(Character* pPlayer) override;
};

#endif

