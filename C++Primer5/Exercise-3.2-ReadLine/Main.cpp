#include <iostream>
#include <string>

int main()
{
	std::string line;

	do
	{
		if (!line.empty())
			std::cout << "You typed : " << line << std::endl;

		std::getline(std::cin, line);
	} while (!line.empty());

	return 0;
}