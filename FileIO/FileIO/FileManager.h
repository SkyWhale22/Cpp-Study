#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <vector>
#include <functional>

typedef std::ios_base FileMode;
#define I 0
#define J 1

class FileManager
{
private:
public:
	FileManager();
	~FileManager();
	std::unordered_map<char, int> m_letters;
	std::unordered_map<std::string, int> m_words;

	void FileReader(const char* pFileName);

	int GetSecond(std::pair<std::string, int> makePair) { return makePair.second; }

	void PrintContents();
	void PrintTexts(const char* fileName, std::unordered_map<std::string, int> map);
	void PutLetterInMap(const char& ch);
	void PutWordInMap(const std::string& pline);
	//Words GetWordMap() { return m_words; }
};