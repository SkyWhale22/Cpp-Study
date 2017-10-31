#pragma once
#include "tinyxml2.h"
#include <string>
#include <unordered_map>
#include "TankStateMachine.h"
#include "CannonShell.h"

using tinyxml2::XMLDocument;
using tinyxml2::XMLElement;


class Vector2;
class TankStateMachine;

typedef std::unordered_map<std::string, std::string> ArenaMap;

class Map
{
public:
	Map();
	~Map();
private:
	XMLDocument doc;
	XMLElement* pRoot;

	ArenaMap m_arena;

public:
	void ReadMap();
	//std::unordered_map<std::string&, std::string&> GetMap(std::string spriteName);
	std::string GetMapSprite(std::string spriteName);

	bool CheckEndOfMapForTank(TankStateMachine::Direction dir, Vector2* pos);
	bool CheckEndOfMapForShell(CannonShell::MovingDirection dir, Vector2* pos);
};

