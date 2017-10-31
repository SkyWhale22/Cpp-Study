#include "CannonShell.h"
#include <iostream>

using tinyxml2::XMLDocument;
using tinyxml2::XMLElement;

CannonShell::CannonShell()
{
	ReadShellSprite();
}


CannonShell::~CannonShell()
{
}

void CannonShell::SetPosition(int x, int y)
{
	m_position.Set(x, y);
}

void CannonShell::SetDirection(MovingDirection dir, Vector2 & pos)
{
	m_dir = dir;

	switch (m_dir)
	{
	case CannonShell::MovingDirection::kLeft:
		m_position.Set(pos.GetX(), pos.GetY() + 1);
		break;
	case CannonShell::MovingDirection::kRight:
		m_position.Set(pos.GetX() + 2, pos.GetY() + 1);
		break;
	case CannonShell::MovingDirection::KUp:
		m_position.Set(pos.GetX() + 1, pos.GetY() + 1);
		break;
	case CannonShell::MovingDirection::kDown:
		m_position.Set(pos.GetX() + 1, pos.GetY() + 2);
		break;
	default:
		break;
	}
}

//----------------------------------------------------
// Moves cannon shell's position depends on direction
//-----------------------------------------------------
void CannonShell::Move()
{
	switch (m_dir)
	{
	case CannonShell::MovingDirection::kLeft:
		m_position.Set(m_position.GetX() - 2, m_position.GetY());
		break;
	case CannonShell::MovingDirection::kRight:
		m_position.Set(m_position.GetX() + 2, m_position.GetY());
		break;
	case CannonShell::MovingDirection::KUp:
		m_position.Set(m_position.GetX(), m_position.GetY() - 2);
		break;
	case CannonShell::MovingDirection::kDown:
		m_position.Set(m_position.GetX(), m_position.GetY() + 2);
		break;
	}
}


void CannonShell::ReadShellSprite()
{
	XMLDocument doc;
	doc.LoadFile("SpriteData.xml");
	XMLElement* pSprite = doc.RootElement();
	XMLElement* pShellSprite = pSprite->FirstChildElement("CannonShell");

	m_sprite = pShellSprite->GetText();
}

std::string CannonShell::GetDirString()
{
	switch (m_dir)
	{
	case CannonShell::MovingDirection::kLeft:
		return "L";
		break;
	case CannonShell::MovingDirection::kRight:
		return "R";
		break;
	case CannonShell::MovingDirection::KUp:
		return "U";
		break;
	case CannonShell::MovingDirection::kDown:
		return "D";
		break;
	}
}

