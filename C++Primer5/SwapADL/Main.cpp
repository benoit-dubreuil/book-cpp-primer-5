#include "B.h"

int main()
{
	B b1{ 1 };
	B b2{ 2 };

	// The swap(B&, B&) function is found because of ADL, as there is a parameter that is of type B
	swap(b1, b2);

	return 0;
}