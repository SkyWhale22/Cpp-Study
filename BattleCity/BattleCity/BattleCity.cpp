#include <vld.h>
#include <iostream>
#include "World.h"
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand((unsigned int)time(nullptr));

	system(" mode  con lines=25  cols=80 ");
	
	World* pWorld = World::GetInstance();
	pWorld->GameProcess();
	pWorld->FreeInstance();

	system("cls");
	system("pause");
	return 0;
}