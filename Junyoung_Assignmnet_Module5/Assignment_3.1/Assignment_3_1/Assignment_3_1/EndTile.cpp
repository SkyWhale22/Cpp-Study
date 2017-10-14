// EndTile.cpp
#include "EndTile.h"
#include <iostream>

EndTile::EndTile()
{
	type = TileType::k_end;
}

void EndTile::Draw()
{
    std::cout << "H";
}

void EndTile::OnEnter(Character* pPlayer)
{
    World::GetInstance()->EndGame();
}
