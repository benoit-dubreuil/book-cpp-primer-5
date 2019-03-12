#include <string>
#include <iostream>

// Exercises 3.6 and 3.8 plus the iterator for loop
int main()
{
	const std::string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
	const decltype(text)::size_type textSize = text.size();

	// Change all characters to X
	
	// Range for loop
	std::string textCopy = text;

	// Or auto &c
	for (decltype(textCopy)::value_type &c : textCopy)
	{
		c = 'X';
	}

	std::cout << textCopy << std::endl;


	// While loop
	textCopy = text;
	decltype(textCopy)::size_type i = 0;

	while (i < textSize)
	{
		textCopy[i] = 'X';
		++i;
	}

	std::cout << textCopy << std::endl;


	// Traditional for loop
	textCopy = text;

	for (decltype(textCopy)::size_type i = 0; i < textSize; ++i)
	{
		textCopy[i] = 'X';
	}

	std::cout << textCopy << std::endl;
	

	// Iterator for loop
	textCopy = text;

	for (decltype(textCopy)::iterator it = textCopy.begin(); it != textCopy.end(); ++it)
	{
		*it = 'X';
	}

	std::cout << textCopy << std::endl;


	const std::string s = "Keep out!";
	for (auto &c : s) { /* ... */ }

	return 0;
}