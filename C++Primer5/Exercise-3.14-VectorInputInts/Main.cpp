#include <iostream>
#include <vector>

int main()
{
	std::vector<int> inputs;
	
	for (unsigned int i = 0; i < 5 && std::cin.good(); ++i)
	{
		decltype(inputs)::value_type intInput;
		std::cin >> intInput;

		if (std::cin.good())
		{
			inputs.push_back(intInput);
		}
	}
	
	decltype(inputs)::size_type const inputsSize = inputs.size();
	for (decltype(inputs)::size_type i = 0; i < inputsSize; ++i)
	{
		std::cout << inputs[i] << '\ ';
	}
	std::cout << std::endl;

	return 0;
}