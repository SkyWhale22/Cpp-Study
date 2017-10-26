#pragma once
#include "tinyxml2.h"

using tinyxml2::XMLDocument;
using tinyxml2::XMLElement;

class Map
{
private:
	static Map* m_pMap;

	XMLDocument doc;
	XMLElement* pRoot;

	Map();
	~Map();

public:
	static Map* GetInstance()
	{
		if (m_pMap == nullptr)
			m_pMap = new Map();

		return m_pMap;
	}

	void FreeInstance()
	{
		delete m_pMap;
		m_pMap = nullptr;
	}

	void ReadMap();
	bool CheckEndOfMap(char ch, int oneOfPosition);
};

