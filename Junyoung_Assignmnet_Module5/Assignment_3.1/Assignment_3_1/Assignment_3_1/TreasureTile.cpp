// TreasureTile.cpp
#include "TreasureTile.h"
#include "Player.h"
#include <iostream>

const TreasureTile::TreasureRange TreasureTile::s_treasureRange(50, 150);

TreasureTile::TreasureTile()
    : m_collected(false)
{
    m_amount = (rand() % (s_treasureRange.second - s_treasureRange.first)) + s_treasureRange.first;
	type = TileType::k_treasure;
}

void TreasureTile::Draw()
{
    if (!m_collected)
        std::cout << "$";
    else
        std::cout << ".";  // floor
}

void TreasureTile::OnEnter(Character* pCharacter)
{
    if (!m_collected)
    {
        ((Player*)pCharacter)->AddGold(m_amount);
        m_collected = true;
    }
}

