
#include <vector>

int main()
{
	int arrayValues[] = { 5, -7, 256, 6, 73, 49, 32, 88, 100, 0 };
	std::vector<int> vectorValues(std::cbegin(arrayValues), std::cend(arrayValues));

	return 0;
}