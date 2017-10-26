#include <vld.h>
#include <iostream>
#include "World.h"
#include <Windows.h>

int main()
{
	system(" mode  con lines=25  cols=80 ");
	
	World* pWorld = World::GetInstance();
	pWorld->GameProcess();
	pWorld->FreeInstance();

	system("pause");
	return 0;
}