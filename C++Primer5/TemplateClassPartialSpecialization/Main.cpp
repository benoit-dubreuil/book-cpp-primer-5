#include <iostream>

// Testing Class template partial specialization and function template specialization

template <typename T>
struct GeneralClass
{
	static void foo()
	{
		std::cout << "GeneralClass<T>, GeneralClass<T>::foo()" << std::endl;
	}

	template <typename E>
	static void bar()
	{
		std::cout << "GeneralClass<T>, GeneralClass<T>::bar<E>()" << std::endl;
	}
};

// Class template partial specialization
template <>
struct GeneralClass<double>
{
	static void foo()
	{
		std::cout << "GeneralClass<double>, GeneralClass<double>::foo()" << std::endl;
	}

	template <typename E>
	static void bar()
	{
		std::cout << "GeneralClass<double>, GeneralClass<double>::bar<E>()" << std::endl;
	}
};

// Class template specific partial specialization
template <>
void GeneralClass<int>::foo()
{
	std::cout << "GeneralClass<int>, GeneralClass<int>::foo()" << std::endl;
}

// Class template specific partial specialization
template <>
template <typename E>
void GeneralClass<int>::bar()
{
	std::cout << "GeneralClass<int>, GeneralClass<int>::bar<E>()" << std::endl;
}

// Class template specific partial specialization and function template specialization
template <>
template <>
void GeneralClass<int>::bar<int>()
{
	std::cout << "GeneralClass<int>, GeneralClass<int>::bar<int>()" << std::endl;
}


int main()
{
	GeneralClass<void>::foo();
	GeneralClass<void>::bar<void>();

	std::cout << std::endl;

	GeneralClass<double>::foo();
	GeneralClass<double>::bar<void>();

	std::cout << std::endl;

	GeneralClass<int>::foo();
	GeneralClass<int>::bar<void>();
	GeneralClass<int>::bar<int>();

	return 0;
}