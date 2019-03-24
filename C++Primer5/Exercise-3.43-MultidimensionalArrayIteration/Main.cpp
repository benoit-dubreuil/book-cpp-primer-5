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
	for (int const (& xElement)[ySize] : ia)
	{
		for (int yElement : xElement)
		{
			std::cout << yElement << ' ';
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Subscript for - 2 dimensions
	for (std::size_t x = 0; x < xSize; ++x)
	{
		for (std::size_t y = 0; y < ySize; ++y)
		{
			std::cout << ia[x][y] << ' ';
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Subscript for - 1 dimension
	for (std::size_t i = 0; i < totalSize; ++i)
	{
		std::size_t x = i / ySize;
		std::size_t y = i % ySize;

		std::cout << ia[x][y] << ' ';

		if (y == ySize - 1)
		{
			std::cout << std::endl;
		}		
	}

	std::cout << std::endl;

	// Pointer for (iterator)
	for (int const (*xElement)[ySize] = std::cbegin(ia); xElement != std::cend(ia); ++xElement)
	{
		for (int const * yElement = std::cbegin(*xElement); yElement != std::cend(*xElement); ++yElement)
		{
			std::cout << *yElement << ' ';
		}

		std::cout << std::endl;
	}

	return 0;
}