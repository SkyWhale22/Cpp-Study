#pragma once
#include "tinyxml2.h"
#include <string>
#include <iostream>

using std::cout;
using std::endl;

using namespace tinyxml2;

class TankStateMachine;
class TankState
{
private:
protected:
	TankStateMachine* m_pStateMachine;
	std::string m_sprite;

	XMLDocument doc;
	XMLElement* pSprite;
	XMLElement* pType;
	XMLElement* pTank;
	XMLElement* pDir;
public:	
	virtual void ReadSprite(char* pName);
	void PrintSprite();
};