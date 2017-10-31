#pragma once
#include "Tank.h"

class Player : public Tank
{

public:
	Player();
	~Player();

	void GetInput(char input);
	bool CheckMovable();
};


