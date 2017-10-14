// BombTile.cpp
#include "BombTile.h"
#include <iostream>

const BombTile::DamageRange BombTile::s_damageRange(3, 6);

BombTile::BombTile()
	: m_pActive(new StateActive())
	, m_pDead(new StateDead())
    , m_pState(m_pActive)
{
	type = TileType::k_bomb;
}

BombTile::~BombTile()
{
}

void BombTile::Draw()
{
	m_pState->PrintTile();
}

void BombTile::OnEnter(Character* pPlayer)
{
	if (m_pState == GetActiveState())
	{
		GiveDamage(pPlayer, s_damageRange);
		SetState(new StateDead());
	}
}