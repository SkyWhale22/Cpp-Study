#include "World.h"

World* World::m_pWorld = nullptr;

World::World()
{
	m_pTank = new Player();
}


World::~World()
{
	delete m_pTank;
}

void World::PrintTank()
{
	m_pTank->PrintTank();
}

void World::MoveTank()
{

}
