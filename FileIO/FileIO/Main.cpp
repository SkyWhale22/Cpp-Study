#include <iostream>
#include <vld.h>
#include <map>
#include <string>
#include <functional>

#include "FileManager.h"
using std::cout;
using std::cin;
using std::endl;
/*
Goals:
	 *Use File I / O to discover data about a file
		 * Write the answers you found to a separate file

		 - Read Leo Tolstoy's "War and Peace" with the program
		 - Two unordered maps
		 - LetterMap <char, int>
		 -WordMap   <std::string, int>

		 -Print the contents of the both maps to their own file
		 - LetterMapContents.txt
		 - WordMapContents.txt

		 - All three files should be in a directory 'data'

		 **** BONUS
		 * Print the Contents from most frequent to least frequent(Maybe use something other than unordered map)
		 * Solve the floating point error(Get creative!)
*/

int GetSecond(std::pair<std::string, int> makePair) { return makePair.second; }

int main()
{
	FileManager fManager;

	//fManager.FileReader(".\\data\\InputTest_2.txt");
	fManager.FileReader(".\\data\\WarAndPeace_LeoTolstoy.txt");
	fManager.PrintTexts();

	cout << endl << endl;

	system("pause");
	return 0;
}