#include "B.h"
#include <iostream>

B::B()
{
}

B::B(int i) : memI{ i }, memA{ i }
{
}

void swap(B& lhs, B& rhs) noexcept
{
	using std::swap;

	// The std::swap function is found because it was made accessible with a using-declaration
	// See https://en.cppreference.com/w/cpp/language/namespace
	// 6) using-declaration: makes the symbol name from the namespace ns_name accessible for unqualified lookup as if declared in the same class scope, block scope, 
	// or namespace as where this using-declaration appears. 
	swap(lhs.memI, lhs.memI);

	// The swap(A&, A&) function for A is found because of ADL, as there is a parameter that is of type A
	swap(lhs.memA, lhs.memA);

	std::cout << "B swap" << std::endl;
}