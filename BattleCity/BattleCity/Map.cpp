#include "Map.h"
#include <iostream>
#include <string.h>

Map* Map::m_pMap = nullptr;

Map::Map()
{
	doc.LoadFile("MapData.xml");
	pRoot = doc.RootElement();
}


Map::~Map()
{
}

void Map::ReadMap()
{
	pRoot = doc.RootElement();
	XMLElement* pMap = pRoot->FirstChildElement("Basic");
	std::string data = "";

	if (pMap == nullptr)
	{
		std::cout << "Couldn't find Map" << std::endl;
	}
	else
		std::cout << pMap->GetText() << std::endl;
}

bool Map::CheckEndOfMap(char ch, int oneOfPosition)
{
	XMLElement* pEndOfMap = pRoot->FirstChildElement("EndOfMap");
	XMLElement* pDirection = pEndOfMap->FirstChildElement();
	switch (ch)
	{
	case 's':	// Down
		pDirection = pEndOfMap->FirstChildElement("South");
		break;
	case 'a':	// Left
		pDirection = pEndOfMap->FirstChildElement("West");
		break;
	case 'd':	// Right
		pDirection = pEndOfMap->FirstChildElement("East");
		break;
	case 'w':	// Up
		pDirection = pEndOfMap->FirstChildElement("North");
		break;
	}

	int value = 0;
	pDirection->QueryIntText(&value);

	if (value == oneOfPosition)
		return true;
	else
		return false;
}
