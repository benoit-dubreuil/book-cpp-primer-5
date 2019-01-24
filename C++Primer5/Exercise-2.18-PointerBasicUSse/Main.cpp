#include <iostream>

int main()
{
	int value = 42;
	int value2 = 6432;
	int *ptr = &value;

	std::cout << "Value : " << *ptr << std::endl;

	ptr = &value2;
	std::cout << "Value : " << *ptr << std::endl;

	*ptr /= 2;
	std::cout << "Value : " << *ptr << std::endl;

	return 0;
}