#ifndef __GLOBALDATA_H__
#define __GLOBALDATA_H__

#include <utility>

const int k_worldWidth = 20;
const int k_worldHeight = 20;

static const int k_maxHitPoints		= 10;
static const int k_baseScore		= 1000;
static const int k_hitPointsWeight	= 100;
static const int k_goldWeight		= 10;
static const int k_moveCountWeight	= 10;

enum class TileType
{
	k_floor,
	k_bomb,
	k_treasure,
	k_mimic,
	k_end,
	k_numTiles
};
#endif