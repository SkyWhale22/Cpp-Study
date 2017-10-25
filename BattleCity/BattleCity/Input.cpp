#include "Input.h"
#include <iostream>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

char Input::GetInput()
{
	while (true)
	{
		if (_kbhit())	// True, only if when gets input.
		{
			system("cls");
			char ch = _getch();	// Saves input itto ch.
			return ch;
		}
	}
}