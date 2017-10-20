// MimicTile.cpp
#include "MimicTile.h"
#include <iostream>

using std::cout;

const DamagingTile::DamageRange MimicTile::m_kdamageRange(3, 6);

MimicTile::MimicTile()
{
	type = TileType::k_mimic;
	m_tileSM.ChangeState(TileStateMachine::State::kHidden);
	m_pDamageAbleTile = new DamagingTile;
}

void MimicTile::Draw()
{
	m_tileSM.GetState()->PrintTile();
}

void MimicTile::OnEnter(Character* pCharacter)
{
	if(m_tileSM.m_isExploaded == false)
	{
		m_pDamageAbleTile->GiveDamage(pCharacter, m_kdamageRange);
		m_tileSM.ChangeState(TileStateMachine::State::kExploaded);
	}
}

void MimicTile::GetDetacted()
{
	//if (m_tileSM.m_isExploaded == false)
		m_tileSM.ChangeState(TileStateMachine::State::kRevealed);
}
