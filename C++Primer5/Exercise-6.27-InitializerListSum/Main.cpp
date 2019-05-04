#include <iostream>
#include <initializer_list>

template <typename T>
T sum(std::initializer_list<T> elements)
{
	T result{};
	
	for (const T& element : elements)
	{
		result += element;
	}

	return result;
}

int main()
{
	std::cout << sum<int>( { } ) << std::endl;
	std::cout << sum<int>( { 5 } ) << std::endl;
	std::cout << sum<int>( { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } ) << std::endl;

	return 0;
}