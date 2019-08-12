#include <iostream>

// Examples of variadic template uses

template<typename T>
std::ostream& printAll(std::ostream& out, const T& arg)
{
	return out << arg << std::endl << std::endl;
}

template<typename T, typename... Args>
std::ostream& printAll(std::ostream& out, const T& arg, const Args&... args)
{
	out << arg << std::endl;
	return printAll(out, args...);
}

// Doesn't work with char*
template<typename T>
std::ostream& printAddAll(std::ostream& out, const T& arg)
{
	return out << (arg + arg) << std::endl << std::endl;
}

// Doesn't work with char*
template<typename T, typename... Args>
std::ostream& printAddAll(std::ostream& out, T arg, Args ... args)
{
	out << (arg + arg) << std::endl;
	return printAddAll(out, (args + args)...);
}

int main()
{
	std::string test("Test");

	printAll(std::cout, 1);
	printAll(std::cout, 1, 2, 3, 4, test);

	printAddAll(std::cout, 1, 2, test);

	return 0;
}