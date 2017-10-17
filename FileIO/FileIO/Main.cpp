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


	std::unordered_map<char, int>* letters;
	std::unordered_map<std::string, int>* words;
	
	letters = &fManager.m_letters;
	words = &fManager.m_words;

	fManager.FileReader(".\\data\\InputTest_2.txt");
	fManager.FileReader(".\\data\\WarAndPeace_LeoTolstoy.txt");
	//fManager.PrintContents();

	//fManager.PrintTexts(".\\data\\LetterMapContents.txt", fManager.GetLetterMap());
	//fManager.PrintTexts(".\\data\\LetterMapContents.txt", fManager.m_words);

	std::vector<int> v(words->size());
	std::vector<std::string> w(words->size());
	transform(words->begin(), words->end(), v.begin(), GetSecond);

	sort(v.begin(), v.end());
	

	for (int i = 0; i<v.size(); i++) std::cout << v[i] << std::endl;

	system("pause");
	return 0;
}