#include "PortalTile.h"
#include "World.h"

PortalTile::PortalTile()
{
	type = TileType::k_potalTiles;
}

void PortalTile::Draw()
{
	std::cout << "&";
}

void PortalTile::OnEnter(Character * pCharacter)
{
	int currentCharacterIndex = (pCharacter->GetY() * k_worldHeight) + pCharacter->GetX();
	World* pWorldData = World::GetInstance();

	if(pWorldData->m_portalPair.find)
}

void PortalTile::MovePlayer()
{
}
