// TreasureTile.h
#ifndef __TREASURETILE_H__
#define __TREASURETILE_H__

#include "Tile.h"
#include <utility>

class TreasureTile : public Tile
{
    typedef std::pair<int, int> TreasureRange;

    static const TreasureRange s_treasureRange;

    int m_amount;
    bool m_collected;

public:
    TreasureTile();
	~TreasureTile() {}
    virtual void Draw() override;
    virtual void OnEnter(Character* pPlayer) override;
};

#endif
