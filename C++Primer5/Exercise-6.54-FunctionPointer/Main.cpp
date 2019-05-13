#include <vector>

int add(int a, int b)
{
	return a + b;
}

// Write a declaration for a function that takes two int parameters and returns an int, and declare a vector whose elements have this function pointer type.
int main()
{
	std::vector<int(*)(int, int)> v1;
	std::vector<decltype(&add)> v2;

	v1.push_back(add);
	v2.push_back(add);

	return 0;
}