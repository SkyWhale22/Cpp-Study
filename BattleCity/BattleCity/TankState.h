#pragma once
#include "tinyxml2.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;

using tinyxml2::XMLDocument;
using tinyxml2::XMLElement;

class TankStateMachine;

class TankState
{
protected:

	XMLDocument doc;
	XMLElement* pSprite;
	XMLElement* pType;
	XMLElement* pTank;
	XMLElement* pDir;

	TankStateMachine* m_pStateMachine;
	std::string m_sprite;

public:	
	virtual void ReadSprite(char* pName);
	void PrintSprite(int posX, int posY);
	std::string& GetSprite() { return m_sprite; }
};