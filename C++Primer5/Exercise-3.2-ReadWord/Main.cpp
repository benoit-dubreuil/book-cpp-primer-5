#include <iostream>
#include <string>

int main()
{
	std::string word;

	std::cout << "Type <q> to quit." << std::endl;

	do
	{
		if (!word.empty())
			std::cout << "You typed : " << word << std::endl;

		std::cin >> word;
	} while (!(word.empty() || word == std::string{ 'q' }));

	return 0;
}