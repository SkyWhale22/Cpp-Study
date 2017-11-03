#include "Input.h"
#include <iostream>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

char Input::GetInput()
{
	char ch;

	if (_kbhit())
	{
		ch = _getch();
		return ch;
	}
	else
		return NULL;
}