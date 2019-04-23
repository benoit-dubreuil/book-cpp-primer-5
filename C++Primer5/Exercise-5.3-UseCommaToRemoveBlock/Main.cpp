#include <iostream>

/*
* Use the comma operator (§ 4.10, p. 157) to rewrite the while loop from § 1.4.1 (p. 11) so that it no longer requires a block.
* Explain whether this rewrite improves or diminishes the readability of this code.
*/
int main()
{
	int sum = 0, val = 1;

	// Do while equivalent
	while (sum += val, ++val, val <= 10); // Null statement

	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;


	sum = 0, val = 1;
	// While equivalent
	while ((val <= 10) ? sum += val, ++val : false); // Null statement

	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

	return 0;
}