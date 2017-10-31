#include "Vector2.h"


Vector2::Vector2()
{
}

Vector2::Vector2(int x, int y)
	: posX(x)
	, posY(y)
{
}


Vector2::~Vector2()
{
}


void Vector2::Set(int x, int y)
{
	posX = x;
	posY = y;
}