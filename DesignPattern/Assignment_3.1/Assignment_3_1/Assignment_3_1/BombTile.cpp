// BombTile.cpp
#include "BombTile.h"
#include <iostream>

const DamagingTile::DamageRange BombTile::s_damageRange(3, 6);

BombTile::BombTile()
{
	type = TileType::k_bomb;
	m_tileSM.ChangeState(TileStateMachine::State::kRevealed);
	m_pDamageAbleTile = new DamagingTile;
}

BombTile::~BombTile()
{
	delete m_pDamageAbleTile;
	m_pDamageAbleTile = nullptr;
}

void BombTile::Draw()
{
	m_tileSM.GetState()->PrintTile();
}

void BombTile::OnEnter(Character* pPlayer)
{
	if (m_tileSM.m_isExploaded == false)
	{
		m_pDamageAbleTile->GiveDamage(pPlayer, s_damageRange);
		m_tileSM.ChangeState(TileStateMachine::State::kExploaded);
	}
}