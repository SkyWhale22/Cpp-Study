#include <vld.h>
#include <iostream>
#include "World.h"

int main()
{
	World* pWorld = World::GetInstance();
	pWorld->FreeInstance();
	system("pause");
	return 0;
}