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

#if (I == 0)

	if (fileReader.is_open())
	{
		while (fileReader.eof() == false)
		{
			if (fileReader.eof() == true)
				break;
			fileReader >> line;
		
			size_t dashFind = line.find_first_of('-');
			
			if (dashFind != std::string::npos)
			{
				continue;
			}

			size_t found = line.find_first_of(".,'#&*\"");
			
			// does the line have a colon?
			if(found != std::string::npos)
			{
				// remove the coma and everything afterwards
				PutLetterInMap(line[found]);
				line = line.substr(0, found);
			}
			
			for (int index = 0; index < line.size(); ++index)
			{
				PutLetterInMap(line[index]);
			}

			PutWordInMap(line);
		}
	}
#elif  (I == 1)
	if (fileReader.is_open())
	{
		while (fileReader.get(letter))
		{
			if (fileReader.eof() == true)
				break;

			if (letter != '\n')
			{
				if (m_letters.find(letter) == m_letters.end())
				{
					if (letter != ' ')
						m_letters.emplace(letter, 1);
				}

				else
					++m_letters[letter];

				if (letter != '"' && letter != '.' && letter != ',' && letter != ' ')
					line += letter;

				else
				{
					if (m_words.find(line) == m_words.end())
						m_words.emplace(line, 1);
					else
						++m_words[line];

					line = "";
				}
			}
		}
		fileReader.close();
	}
#endif
	else
	{   
		std::cout << "Couldn't open " << pFileName;
	}
}

void FileManager::PrintContents()
{
#if (J == 0)
	for (auto& it = m_words.begin(); it != m_words.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}

#elif (J == 1)
	std::cout << std::endl;

	for (auto& it = m_words.begin(); it != m_words.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}

	for (auto& it = m_letters.begin(); it != m_letters.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}
#endif // !j == 0
}

void FileManager::PrintTexts(const char* fileName, std::unordered_map<std::string, int> map)
{
	// Create ofstream
	std::ofstream fileWriter;

	// Open a file
	fileWriter.open(fileName, FileMode::out);
	
	// Test if it's open
	if (fileWriter.is_open())
	{
		std::string data;
		for (auto& it = map.begin(); it != map.end(); ++it)
		{
			fileWriter << it->first << " : " << it->second << std::endl;
		}

		// Write some data!

		// Close the file
		fileWriter.close();
	}
	else
	{
		std::cout << "Could not open: " << fileName << std::endl;
	}

}

void FileManager::PutLetterInMap(const char & ch)
{
	if (m_letters.find(ch) == m_letters.end())
		m_letters.emplace(ch, 1);
	else
		++m_letters.find(ch)->second;
}

void FileManager::PutWordInMap(const std::string&  pline)
{
	if (m_words.find(pline) == m_words.end())
		m_words.emplace(pline, 1);
	else
		++m_words.find(pline)->second;
}