#include <iostream>
#include <vector>

int main()
{
	std::vector<int> values = { 5, -7, 256, 6, 73, 49, 32, 88, 100, 0 };

	for (auto it = values.begin(); it != values.end(); ++it)
	{
		*it *= 2;
	}

	for (auto it = values.cbegin(); it != values.cend(); ++it)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}