#include <string>
#include <cctype>
#include <iostream>

int main()
{
	// Read from input, then output what was read but without the punctuation

	std::string input;
	std::cin >> input;

	std::string output;
	for (auto const c : input)
	{
		if (!std::ispunct(c))
			output += c;
	}

	std::cout << output << std::endl;

	return 0;
}