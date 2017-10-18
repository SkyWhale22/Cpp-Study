#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <functional>

typedef std::ios_base FileMode;
#define I 0
#define J 0

typedef std::pair<std::string, int> WordPair;
typedef std::pair<char, int> LetterPair;

struct WordMapByValue 
{
	bool operator() (const WordPair& a, const WordPair& b) const
	{
		return a.second < b.second;
	};
};

struct LetterMapByValue
{
	bool operator() (const LetterPair& a, const LetterPair& b) const
	{
		return a.second < b.second;
	};
};


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

	void PrintTexts();
	void PutLetterInMap(const char& ch);
	void PutWordInMap(const std::string& pline);
};