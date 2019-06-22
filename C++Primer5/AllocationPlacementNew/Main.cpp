#include <iostream>

struct Test
{
	int a;
	int b;

	Test()
	{
		std::cout << typeid(*this).name() << " constructor" << std::endl;
	}

	Test(int a, int b) : a(a), b(b)
	{
		std::cout << typeid(*this).name() << " constructor" << std::endl;
	}

	~Test()
	{
		std::cout << typeid(*this).name() << " destructor" << std::endl;
	}

	void* operator new(size_t size)
	{
		std::cout << "new " << size << " bytes" << std::endl;
		return ::operator new(size);
	}

	void operator delete(void* p)
	{
		std::cout << "delete" << std::endl;
		::operator delete(p);
	}
};

int main()
{
	std::cout << "Test 1" << std::endl;
	{
		Test* test = static_cast<Test*>(operator new(sizeof(Test)));

		::new (test) Test; // Call constructor, placement new
		test->~Test();

		::operator delete(test);
	}

	std::cout << "Test 2" << std::endl;
	{
		std::size_t const arraySize = 5;
		Test* test = static_cast<Test*>(operator new(sizeof(Test) * arraySize));

		for (std::size_t i = 0; i < arraySize; ++i)
		{
			::new (test + i) Test(1, 9); // Call constructor, placement new
		}

		for (std::size_t i = 0; i < arraySize; ++i)
		{
			test[i].~Test();
		}

		::operator delete[](test);
	}
	
	return 0;
}