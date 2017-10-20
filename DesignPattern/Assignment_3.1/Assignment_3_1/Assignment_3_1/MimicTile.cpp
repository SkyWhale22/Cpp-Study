// MimicTile.cpp
#include "MimicTile.h"
#include <iostream>

using std::cout;

const DamagingTile::DamageRange MimicTile::m_kdamageRange(3, 6);

//---------------------------------------------------------------
// Note :
// I have used state pattern on mimic tile and bomb tile,
// because it shares same function, and characters.
//---------------------------------------------------------------



MimicTile::MimicTile()
{
	type = TileType::k_mimic;
	m_tileSM.ChangeState(TileStateMachine::State::kHidden);
	m_pDamageAbleTile = new DamagingTile;
}

MimicTile::~MimicTile()
{
	delete m_pDamageAbleTile;
	m_pDamageAbleTile = nullptr;
}

//---------------------------------------------------------------
// Draws it's character depends on its state.
//---------------------------------------------------------------
void MimicTile::Draw()
{
	m_tileSM.GetState()->PrintTile();
}

//---------------------------------------------------------------
// If a character steps on it, gives damages to it.
//---------------------------------------------------------------
void MimicTile::OnEnter(Character* pCharacter)
{
	if(m_tileSM.m_isExploaded == false)
	{
		m_pDamageAbleTile->GiveDamage(pCharacter, m_kdamageRange);
		m_tileSM.ChangeState(TileStateMachine::State::kExploaded);
	}
}

//---------------------------------------------------------------
// A mimic is detected by the player.
// Changes its state to reveald state.
//---------------------------------------------------------------
void MimicTile::GetDetacted()
{
	m_tileSM.ChangeState(TileStateMachine::State::kRevealed);
}
