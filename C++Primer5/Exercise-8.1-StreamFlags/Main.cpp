#include <iostream>
#include <type_traits>
#include <sstream>

std::istream& readAll(std::istream& input) {
	if (input && std::cout) {

		// The string is range-contsructed from istreambuf_iterator, which iterates over unformatted characters until it becomes equal to a default-constructed input iterator, aka "end of stream".
		// See Scott Meyers, Effective STL Item 29: Consider istreambuf_iterators for character-by-character input.
		// https://stackoverflow.com/questions/3203452/how-to-read-entire-stream-into-a-stdstring
		std::string data(std::remove_reference<decltype(input)>::type::_Iter(input), {});
		std::cout << data;

		input.clear(input.rdstate() & ~input.failbit & ~input.eofbit);
	}

	return input;
}

int main() {
	std::string input("I am data.");
	std::istringstream strStream(input);
	readAll(strStream);

	return 0;
}