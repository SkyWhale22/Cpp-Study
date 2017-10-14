#pragma once
#include "Tile.h"
class PortalTile :
	public Tile
{
public:
	PortalTile();

	void Draw() override;
	void OnEnter(Character* pCharacter) override;

	void MovePlayer();
};

