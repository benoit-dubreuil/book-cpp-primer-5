#include <iostream>
#include <iterator>

int main()
{
	int values1[] = { 5, -7, 256, 6, 73, 49, 32, 88, 100, 0 };
	int values2[] = { 5, -7, 256, 6, 73, 49, 32, 88, 100, 0 };

	int *values1Begin = values1;
	int *values1End = values1Begin + (sizeof(values1) / sizeof(*values1));

	for (auto it = values1Begin; it != values1End; ++it)
	{
		(*it) = 0;
	}

	auto values2Begin = std::cbegin(values2);
	auto *values2End = std::cend(values2);

	for (auto it = values2Begin; it != values2End; ++it)
	{
		std::cout << *(values1Begin + (it - values2Begin)) << std::endl;
		std::cout << *it << std::endl;
	}

	return 0;
}