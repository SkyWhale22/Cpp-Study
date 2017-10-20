// BombTile.h
#ifndef __BOMBTILE_H__
#define __BOMBTILE_H__

#include "Tile.h"
#include "DamagingTile.h"
#include "TileStateMachine.h"

class BombTile : public Tile
{
private:
	DamagingTile* m_pDamageAbleTile;
	static const DamagingTile::DamageRange s_damageRange;
	TileStateMachine m_tileSM;

public:
    BombTile();
	~BombTile();
    virtual void Draw() override;
    virtual void OnEnter(Character* pPlayer) override;
};
#endif

