#pragma once
#include "Vector2.h"
class CollisionChecker
{
public:
	CollisionChecker();
	~CollisionChecker();

	// Checks Collisions bet/ two tanks.
	bool ColBetweenTwoObjs(int x1, int y1, int x2, int y2);
};

