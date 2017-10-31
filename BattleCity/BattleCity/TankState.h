#pragma once
#include "tinyxml2.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;

class TankStateMachine;

class TankState
{
protected:

	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* pSprite;
	tinyxml2::XMLElement* pTank;
	tinyxml2::XMLElement* pDir;

	TankStateMachine* m_pStateMachine;
	std::string m_sprite;

public:	
	virtual void ReadSprite(char* pName);
	std::string& GetSprite() { return m_sprite; }
};