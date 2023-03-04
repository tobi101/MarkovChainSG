#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


/*
* 1. Parser
* In: Sentence
* Out: Hash maps of words
* 
* -- unic_word - hash map for unic words of sentence
* -- start_word - hash map for start words of sentence
* -- end_word - hash map for end words of sentence
*/


// Text to Vector of Hash Maps
std::vector<std::unordered_map<std::string, int>> parser(std::string input_text)
{
	bool isStart = true;
	bool isEnd = false;

	std::string tempStr = "";
	char nextChar = ' ';

	std::vector<std::unordered_map<std::string, int>> wordArr[3];

	std::unordered_map<std::string, int> unic_word;
	std::unordered_map<std::string, int> start_word;
	std::unordered_map<std::string, int> end_word;

	// unic_word
	for (int i = 0; i < input_text.length(); i++)
	{
		nextChar = input_text[i + 1];

		if ((input_text[i] >= 65 && input_text[i] <= 90) || 
			(input_text[i] >= 97 && input_text[i] <= 122))
		{
			tempStr += input_text[i];

		}
		else if (
			input_text[i] == '.' ||
			input_text[i] == '!' ||
			input_text[i] == '?')
		{
			if (end_word.find(tempStr) == end_word.end())
			{
				end_word.insert({ tempStr, 1 });
			}
			else
			{
				end_word[tempStr]++;
			}

			tempStr = "";

			if (nextChar == ' ')
			{
				i++;
			}

			isStart = true;
		}
		else if (input_text[i] == ' ')
		{
			if (isStart)
			{
				if (start_word.find(tempStr) == start_word.end())
				{
					start_word.insert({ tempStr, 1 });
				}
				else
				{
					start_word[tempStr]++;
				}

				isStart = false;
			}
			else
			{
				if (unic_word.find(tempStr) == unic_word.end())
				{
					unic_word.insert({ tempStr, 1 });
				}
				else
				{
					unic_word[tempStr]++;
				}
			}

			tempStr = "";
		}
	}

	wordArr->push_back(unic_word);
	wordArr->push_back(start_word);
	wordArr->push_back(end_word);

	// Test cycles for unordered maps
	std::cout << "unic_word: " << std::endl;
	for (auto& pair : unic_word)
	{
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "start_word: " << std::endl;
	for (auto& pair : start_word)
	{
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "end_word: " << std::endl;
	for (auto& pair : end_word)
	{
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
	std::cout << std::endl;

	return *wordArr;
}


int main()
{
	std::string str = "";
	std::getline(std::cin, str);

	parser(str);
	return 0;
}