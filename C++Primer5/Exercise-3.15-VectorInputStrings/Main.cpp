#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> inputs;

	for (unsigned int i = 0; i < 5 && std::cin.good(); ++i)
	{
		decltype(inputs)::value_type strInput;
		std::cin >> strInput;

		if (std::cin.good())
		{
			inputs.push_back(strInput);
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