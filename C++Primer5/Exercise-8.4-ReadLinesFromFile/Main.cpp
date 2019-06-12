#include <fstream>
#include <iostream>
#include <vector>
#include <string>

constexpr auto FILE_PATH = "FileToRead.txt";

int main(int argc, char *argv[])
{
	int exitCode = 0;

	std::vector<std::string> lines;
	std::ifstream file(FILE_PATH);

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			lines.push_back(line);
		}

		if (file.bad())
		{
			exitCode = 1;
		}
	}
	else
	{
		exitCode = 2;
	}

	for (const std::string &line : lines)
	{
		std::cout << line << std::endl;
	}

	return exitCode;
}