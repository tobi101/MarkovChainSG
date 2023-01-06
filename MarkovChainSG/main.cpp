#include <iostream>
#include <string>

	
float** parser(std::string input_text)
{
	std::string unic_word[100] = {};
	std::string start_word[100] = {};
	std::string end_word[100] = {};
	
	bool isStart = true;
	bool isEnd = false;

	float** transition_matrix = {};

	for (int i = 0; i < input_text.length(); i++)
	{
		if (isStart == true)
		{
			// ...write here...
			isStart == false;
		}
	}

	return transition_matrix;
}


int main()
{

	std::cout << "Hello, world!" << std::endl;
	return 0;
}