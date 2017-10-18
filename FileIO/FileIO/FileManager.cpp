#include "FileManager.h"

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

void FileManager::FileReader(const char* pFileName)
{
	std::ifstream fileReader(pFileName, FileMode::in);

	//fileReader.open(pFileName);
	std::string line;

	if (fileReader.is_open())
	{
		int messageLine = 0;

		while (fileReader.eof() == false)
		{
			if (fileReader.eof() == true)
				break;
			fileReader >> line;

			if (line == "\n")
				std::cout << std::endl;

			size_t dashFind = line.find_first_of('-^');
			
			if (dashFind != std::string::npos)
			{
				PutLetterInMap(line[dashFind]);
				line = line.substr(0, dashFind) + line.substr(dashFind + 1, line.size());
			}

			size_t found = line.find_first_of(".,'#&*\"?/;!()");
			
			// does the line have a symbol?
			if(found != std::string::npos)
			{
				// remove the symbol
				PutLetterInMap(line[found]);
				line = line.substr(0, found);
			}
			
			for (size_t index = 0; index < line.size(); ++index)
			{
				PutLetterInMap(line[index]);
			}

			PutWordInMap(line);
		}
	}

	else
	{   
		std::cout << "Couldn't open " << pFileName; 
	}
}

void FileManager::PrintTexts()
{
	// Create ofstream
	std::vector<std::pair<std::string, int>> word(m_words.begin(), m_words.end());
	std::vector<std::pair<char, int>> letter(m_letters.begin(), m_letters.end());

	std::sort(word.begin(), word.end(), WordMapByValue());
	std::sort(letter.begin(), letter.end(), LetterMapByValue());

	std::ofstream fileWriter;

	char* firstFile = ".\\data\\WordMapContents.txt";
	char* secondFile = ".\\data\\LetterMapContents.txt";

	// Open a file
	fileWriter.open(firstFile, FileMode::out);
	
	// Test if it's open
	if (fileWriter.is_open())
	{
		for (WordPair it : word)
		{
			std::cout << it.first << " : " << it.second << std::endl;
			fileWriter << it.first << " : " << it.second << std::endl;
		}

		// Close the file
		fileWriter.close();
	}
	else
	{
		std::cout << "Could not open: " << firstFile << std::endl;
	}

	fileWriter.open(secondFile, FileMode::out);

	if (fileWriter.is_open())
	{
		for (LetterPair it : letter)
		{
			std::cout << it.first << " : " << it.second << std::endl;
			fileWriter << it.first << " : " << it.second << std::endl;
		}

		// Close the file
		fileWriter.close();
	}

	else
	{
		std::cout << "Could not open: " << firstFile << std::endl;
	}

	std::cout << "\nLetter and word Data has been extracted to .txt files. Please check it." << std::endl;
}

void FileManager::PutLetterInMap(const char & ch)
{
	if (m_letters.find(ch) == m_letters.end())
		m_letters.emplace(ch, 1);
	else
		++m_letters[ch];
}

void FileManager::PutWordInMap(const std::string&  pline)
{

	if (m_words.find(pline) == m_words.end())
		m_words.emplace(pline, 1);
	else
		++m_words[pline];
}