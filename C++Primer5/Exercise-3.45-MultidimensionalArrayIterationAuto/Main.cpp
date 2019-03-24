#include <iostream>
#include <iterator>

int main()
{
	// Taken from the exercise 3.43 statement
	constexpr std::size_t xSize = 3;
	constexpr std::size_t ySize = 4;
	constexpr std::size_t totalSize = xSize * ySize;

	int ia[xSize][ySize] = {
		{0, 1, 2, 3},
		{4, 5, 6, 7},
		{8, 9, 10, 11}
	};

	// Range for
	for (auto const &xElement : ia)
	{
		for (auto yElement : xElement)
		{
			std::cout << yElement << ' ';
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Subscript for - 2 dimensions
	for (auto x = 0; x < xSize; ++x)
	{
		for (auto y = 0; y < ySize; ++y)
		{
			std::cout << ia[x][y] << ' ';
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Subscript for - 1 dimension
	for (auto i = 0; i < totalSize; ++i)
	{
		auto const x = i / ySize;
		auto const y = i % ySize;

		std::cout << ia[x][y] << ' ';

		if (y == ySize - 1)
		{
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;

	// Pointer for (iterator) - 2 dimensions
	for (auto xIt = std::cbegin(ia); xIt != std::cend(ia); ++xIt)
	{
		for (auto yIt = std::cbegin(*xIt); yIt != std::cend(*xIt); ++yIt)
		{
			std::cout << *yIt << ' ';
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Pointer for (iterator) - 1 dimension. *ia works as a pointer because arrays are implicitly pointers.
	for (auto it = *ia; it != (*ia) + totalSize; ++it)
	{
		std::cout << *it << ' ';

		auto const y = (it - (*ia)) % ySize;
		if (y == ySize - 1)
		{
			std::cout << std::endl;
		}
	}

	return 0;
}