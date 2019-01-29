#include <iostream>
#include <string>

int main()
{
	std::string line1;
	std::string line2;

	do
	{
		if (!(line1.empty() && line2.empty()))
		{
			if (line1 == line2)
				std::cout << "The two string are equal." << std::endl;
			else
			{
				std::string largestLineWord;

				if (line1 > line2)
					largestLineWord = "first";
				else
					largestLineWord = "second";

				std::cout << "The " << largestLineWord << " string is the largest." << std::endl;
			}

			std::cout << std::endl;
		}

		std::cout << "Enter the first string : ";
		std::getline(std::cin, line1);
		
		std::cout << "Enter the second string : ";
		std::getline(std::cin, line2);

	} while (!(line1.empty() && line2.empty()));

	return 0;
}