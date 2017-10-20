#include <iostream>
#include <vld.h>
#include <map>
#include <string>
#include <functional>
#include <float.h>
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

	//---------------------------------------------------------------------
	// How to avoid the floating point error.
	//---------------------------------------------------------------------

	// 1. Better to use double. It is more accurate than float, but not perfect.
	double a = 12.34;
	double a1 = 12.3456;


	// 2. Add 1 * 2^23, then drop upper exponential bits.
	typedef union { int i; float f; } INTORFLOAT;

	INTORFLOAT n;
	INTORFLOAT bias;

	bias.i = (23 + 127) << 23;

	n.f = 123.456f;
	n.f += bias.f;
	n.i -= bias.i;

	float b = n.i;
	float c = bias.i;
	
	// 3. Using epsilon.
	float num1 = 0.0f;
	float num2 = 0.1f;

	for (int i = 0; i < 10; i++)
	{
		num1 = num1 + num2;
	}
	
	if (fabsf(num1 - 1.0f) <= FLT_EPSILON)
	{
		//  Calculate the difference between calculated value and value to be compared
		//	If the difference is less than or equal to FLT_EPSILON, it is regared to be the same value.
		printf("true\n");  
	}
	else
		printf("false\n");



	// 4. In C# you can use 'decimal' type value.
	system("pause");
	return 0;
}