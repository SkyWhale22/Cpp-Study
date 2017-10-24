#pragma once
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Tank
{
private:
	int m_HP;
	char* m_pHeadSprite;
	char* m_pBodySprite;
public:
	virtual ~Tank() {};

	virtual void PrintTank() = 0;
	virtual void Move() = 0;
	virtual void Action() = 0;
};

