#include <vector>

int main()
{

	std::vector<int> vectorValues = { 5, -7, 256, 6, 73, 49, 32, 88, 100, 0 };
	int arrayValues[10];

	const decltype(vectorValues)::size_type size = vectorValues.size();
	for (std::size_t i = 0; i < size; ++i)
	{
		arrayValues[i] = vectorValues[i];
	}

	return 0;
}