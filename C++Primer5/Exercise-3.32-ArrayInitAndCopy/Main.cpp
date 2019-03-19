#include <type_traits>

int main()
{
	int values[10];

	// This allows to not derefence the first element. It was done only for the purpose of testing. 
	// The reason why it is necessary to remove references is because the * operator on an array is equivalent to &array[0].
	for (std::size_t i = 0; i < (sizeof(values) / sizeof(std::remove_reference<decltype(*values)>::type)); ++i)
	{
		values[i] = static_cast<int>(i);
	}

	int valuesCopy[sizeof(values) / sizeof(*values)];

	for (std::size_t i = 0; i < (sizeof(values) / sizeof(*values)); ++i)
	{
		valuesCopy[i] = values[i];
	}

	return 0;
}