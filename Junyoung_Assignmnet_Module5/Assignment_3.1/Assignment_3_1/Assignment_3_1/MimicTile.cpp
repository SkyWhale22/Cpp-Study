// MimicTile.cpp
#include "MimicTile.h"
#include <iostream>

using std::cout;

const MimicTile::DamageRange MimicTile::s_damageRange(3, 6);

MimicTile::MimicTile()
	: m_pHidden(new StateHidden())
	, m_pRevealed(new StateRevealed())
	, m_pExploded(new StateExploded())
	, m_pState(m_pHidden)
{
	type = TileType::k_mimic;
}

MimicTile::~MimicTile()
{
	delete m_pState;
}

void MimicTile::Draw()
{
	m_pState->PrintTile();
}

void MimicTile::OnEnter(Character* pCharacter)
{
	if(m_pState == GetHiddenState() || m_pState == GetRevealedState())
	{
		GiveDamage(pCharacter, s_damageRange);
		SetState(new StateExploded());
	}
}