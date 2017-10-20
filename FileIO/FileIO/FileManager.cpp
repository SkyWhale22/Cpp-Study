#include "FileManager.h"

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

//----------------------------------------------------------------------------------------------------
// Reads the content in the file and distributes it in words and letters.
// Adds each words and letters in unorderd_map. If the map doesn't have that word or letter, create
// new key and its value. If the map has, increase its value.
//----------------------------------------------------------------------------------------------------
void FileManager::FileReader(const char* pFileName)
{
	std::cout << "Extracting data to .txt files. Please wait for minutes..." << std::endl << std::endl;

	std::ifstream fileReader(pFileName, FileMode::in);

	std::string line;

	if (fileReader.is_open())
	{
		std::cout << "Successfuly open " << pFileName << " !" << std::endl << std::endl;
		// Keep continue
		while (fileReader.eof() == false)
		{
			// If it reasches the end of the file, escape the loop.
			if (fileReader.eof() == true)
				break;

			fileReader >> line;

			if (line == "\n")
				std::cout << std::endl;
			//^
			size_t dashFind = line.find_first_of('^-');
			
			// If the line has one of symbols above, remove that symbol and make it perfect word.
			if (dashFind != std::string::npos)
			{
				// Adds that sysmbol in map.
				PutLetterInMap(line[dashFind]);
				line = line.substr(0, dashFind) + line.substr(dashFind + 1, line.size());
			}

			size_t found = line.find_first_of(".,'#&*\"?/;!()");
			
			// Does the line have a symbol at the end?
			if(found != std::string::npos)
			{
				// remove the symbol
				PutLetterInMap(line[found]);
				line = line.substr(0, found);
			}
			
			// Puts each letters in the map.
			for (size_t index = 0; index < line.size(); ++index)
			{
				PutLetterInMap(line[index]);
			}

			// Puts a word in the map.
			PutWordInMap(line);
		}
	}

	// If it can't open the file, show this message.
	else
	{   
		std::cout << "Couldn't open " << pFileName; 
	}
}

//----------------------------------------------------------------------------------------------------
// Prints indexes from the letter map and the word map into .txt files.
//----------------------------------------------------------------------------------------------------
void FileManager::PrintTexts()
{
	// Create ofstream
	std::ofstream fileWriter;
	
	// For sorting it in descending order.
	std::vector<std::pair<std::string, int>> word(m_words.begin(), m_words.end());
	std::vector<std::pair<char, int>> letter(m_letters.begin(), m_letters.end());

	std::sort(word.begin(), word.end(), WordMapByValue());
	std::sort(letter.begin(), letter.end(), LetterMapByValue());

	// .txt file directroy
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

	// Open again!
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

//----------------------------------------------------------------------------------------------------
// Puts a letter in the letter map.
//----------------------------------------------------------------------------------------------------
void FileManager::PutLetterInMap(const char & ch)
{
	if (m_letters.find(ch) == m_letters.end())
		m_letters.emplace(ch, 1);
	else
		++m_letters[ch];
}

//----------------------------------------------------------------------------------------------------
// Put a word in the word map.
//----------------------------------------------------------------------------------------------------
void FileManager::PutWordInMap(const std::string&  pline)
{

	if (m_words.find(pline) == m_words.end())
		m_words.emplace(pline, 1);
	else
		++m_words[pline];
}