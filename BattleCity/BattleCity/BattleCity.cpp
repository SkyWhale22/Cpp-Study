#include <vld.h>
#include <iostream>
#include "World.h"
#include "Tank.h"
#include "Player.h"

int main()
{
	World* pWorld = World::GetInstance();
	

	Player testPlayer;
	testPlayer.Update();
	//testPlayer.Move();
	
	pWorld->FreeInstance();
	system("pause");
	return 0;
}