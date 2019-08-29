#include "A.h"
#include <iostream>

A::A()
{
}

A::A(int i) : memI{ i }
{
}

void swap(A& lhs, A& rhs) noexcept
{
	using std::swap;

	// The std::swap function is found because it was made accessible with a using-declaration
	// See https://en.cppreference.com/w/cpp/language/namespace
	// 6) using-declaration: makes the symbol name from the namespace ns_name accessible for unqualified lookup as if declared in the same class scope, block scope, 
	// or namespace as where this using-declaration appears. 
	swap(lhs.memI, rhs.memI);

	std::cout << "A swap" << std::endl;
}