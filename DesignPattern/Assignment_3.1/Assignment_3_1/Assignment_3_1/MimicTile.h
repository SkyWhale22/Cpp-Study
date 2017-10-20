// MimicTile.h
#ifndef __MIMICTILE_H__
#define __MIMICTILE_H__

#include "Tile.h"
#include "DamagingTile.h"
#include "TileStateMachine.h"

class MimicTile : public Tile
{
private:
	DamagingTile* m_pDamageAbleTile;
	static const DamagingTile::DamageRange m_kdamageRange;
	TileStateMachine m_tileSM;

public:
    MimicTile();
	~MimicTile() {}
    virtual void Draw() override;
    virtual void OnEnter(Character* pCharacter) override;

	void GetDetacted();
};

#endif