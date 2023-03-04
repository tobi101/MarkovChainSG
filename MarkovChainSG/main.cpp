#include <iostream>
#include <string>
#include <unordered_map>


/*
* 1. Парсер
* In: Sentence
* Out: Transition Matrix
* 
* -- unic_word - hash map for unic words
* -- start_word - hash map for start words
* -- end_word - hash map for end words
*/


// Text to Transition Matrix
float** TextToMatrix(std::string input_text)
{
	bool isStart = true;
	bool isEnd = false;

	std::string tempStr = "";
	char nextChar = ' ';

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

	float** transition_matrix = {};

	return transition_matrix;
}


int main()
{
	std::string str = "";
	std::getline(std::cin, str);

	TextToMatrix(str);
	return 0;
}