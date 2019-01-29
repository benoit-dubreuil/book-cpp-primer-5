#include <iostream>
#include <string>

int main()
{
	std::string word;
	std::string text;

	std::cout << "Write strings that should be concatenated by the program." << std::endl;

	do
	{
		if (!word.empty())
		{
			if (text.length())
				text += ' ';

			text += word;
			std::cout << text << std::endl;
		}

		std::cin >> word;

	} while (!word.empty());

	return 0;
}