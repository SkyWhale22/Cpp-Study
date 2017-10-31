#include "Map.h"
#include <iostream>
#include <string.h>
#include "Vector2.h"

Map::Map()
{
	doc.LoadFile("MapData.xml");
	pRoot = doc.RootElement();
}


Map::~Map()
{
}

//------------------------------------------------------------------------
// Reads map related data from the MapData.xml.
// Emplaces it in map.
//------------------------------------------------------------------------
void Map::ReadMap()
{
	pRoot = doc.RootElement();

	XMLElement* pMapStructure = pRoot->FirstChildElement("MapStructure");
	XMLElement* pInner = pMapStructure->FirstChildElement("TopBottom");
	XMLElement* pSide = pMapStructure->FirstChildElement("Side");
	XMLElement* pOutLine = pMapStructure->FirstChildElement("OutLine");
	XMLElement* pOutLineSide = pMapStructure->FirstChildElement("OutLineSide");

	m_arena.emplace("TopBottom", pInner->GetText());
	m_arena.emplace("Side", pSide->GetText());
	m_arena.emplace("OutLine", pOutLine->GetText());
	m_arena.emplace("OutLineSide", pOutLineSide->GetText());
}

//std::unordered_map<std::string, std::string> Map::GetMap(std::string spriteName)
std::string Map::GetMapSprite(std::string spriteName)
{
	 return m_arena.find(spriteName)->second;
}


//bool Map::CheckEndOfMap(char ch, Vector2* pos)
bool Map::CheckEndOfMapForTank(TankStateMachine::Direction dir, Vector2* pos)
{
	XMLElement* pEndOfMap = pRoot->FirstChildElement("EndOfMap");
	XMLElement* pForTank = pEndOfMap->FirstChildElement("ForTank");
	XMLElement* pDirection = pForTank->FirstChildElement();

	int posValue;
	switch (dir)
	{
	case TankStateMachine::Direction::kDown:
		pDirection = pForTank->FirstChildElement("South");
		posValue = pos->GetY();
		break;
	case TankStateMachine::Direction::kUp:
		pDirection = pForTank->FirstChildElement("North");
		posValue = pos->GetY();
		break;
	case TankStateMachine::Direction::kRight:
		pDirection = pForTank->FirstChildElement("East");
		posValue = pos->GetX();
		break;
	case TankStateMachine::Direction::kLeft:
		pDirection = pForTank->FirstChildElement("West");
		posValue = pos->GetX();
		break;

	}
		/*
	switch (ch)
	{
	case 's':	// Down
		pDirection = pEndOfMap->FirstChildElement("South");
		posValue = pos->GetY();
		break;
	case 'a':	// Left
		pDirection = pEndOfMap->FirstChildElement("West");
		posValue = pos->GetX();
		break;
	case 'd':	// Right
		pDirection = pEndOfMap->FirstChildElement("East");
		posValue = pos->GetX();
		break;
	case 'w':	// Up
		pDirection = pEndOfMap->FirstChildElement("North");
		posValue = pos->GetY();
		break;
	default:
		pDirection = pEndOfMap->FirstChildElement("Nothing");
		posValue = 0;
		break;
	}
	*/

	int value = 0;
	pDirection->QueryIntText(&value);

	if (value == posValue)
		return true;
	else
		return false;
}

bool Map::CheckEndOfMapForShell(CannonShell::MovingDirection dir, Vector2 * pos)
{
	XMLElement* pEndOfMap = pRoot->FirstChildElement("EndOfMap");
	XMLElement* pForShell = pEndOfMap->FirstChildElement("ForShell");
	XMLElement* pDirection = pForShell->FirstChildElement();

	int posValue;
	int value = 0;
	switch (dir)
	{
	case CannonShell::MovingDirection::kDown:
		pDirection = pForShell->FirstChildElement("South");
		posValue = pos->GetY();
		pDirection->QueryIntText(&value);

		if (value <= posValue)
			return true;
		else
			return false;
		break;
	case CannonShell::MovingDirection::KUp:
		pDirection = pForShell->FirstChildElement("North");
		posValue = pos->GetY();
		pDirection->QueryIntText(&value);

		if (value >= posValue)
			return true;
		else
			return false;

		break;
	case CannonShell::MovingDirection::kRight:
		pDirection = pForShell->FirstChildElement("East");
		posValue = pos->GetX();
		pDirection->QueryIntText(&value);

		if (value <= posValue)
			return true;
		else
			return false;

		break;
	case CannonShell::MovingDirection::kLeft:
		pDirection = pForShell->FirstChildElement("West");
		posValue = pos->GetX();
		pDirection->QueryIntText(&value);

		if (value >= posValue)
			return true;
		else
			return false;

		break;

	}
}
