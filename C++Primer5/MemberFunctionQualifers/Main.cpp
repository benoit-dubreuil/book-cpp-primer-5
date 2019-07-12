#include <iostream>

struct Foo
{
	static Foo makeValue()
	{
		return Foo();
	}

	static Foo const makeConstValue()
	{
		return Foo();
	}

	void test() &
	{
		std::cout << "Test lvalue" << std::endl;
	}

	void test() const &
	{
		std::cout << "Test const lvalue" << std::endl;
	}

	void test() &&
	{
		std::cout << "Test rvalue" << std::endl;
	}

	void test() const &&
	{
		std::cout << "Test const rvalue" << std::endl;
	}
};

int main()
{
	Foo lvalue;
	Foo const constLvalue;
	
	lvalue.test();
	constLvalue.test();

	Foo::makeValue().test();
	Foo::makeConstValue().test();

	return 0;
}