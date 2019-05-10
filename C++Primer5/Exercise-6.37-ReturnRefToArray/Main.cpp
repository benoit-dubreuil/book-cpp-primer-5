#include <string>

constexpr std::size_t ARRAY_SIZE = 10;

// Write the declaration for a function that returns a reference to an array of ten strings.

// Directly
std::string(&getRefToArray())[ARRAY_SIZE];

// Typedef alias
// typedef std::string(&strArrayDef)[ARRAY_SIZE];
// strArrayDef getRefToArray();
typedef std::string strArrayDef[ARRAY_SIZE];
strArrayDef &getRefToArray();

// Using alias
// using strArrayDef = std::string(&)[10];
// strArrayDef getRefToArray();
using strArrayDef = std::string[ARRAY_SIZE];
strArrayDef &getRefToArray();

// Trailing return type
auto getRefToArray()->std::string(&)[ARRAY_SIZE];

// Decltype
std::string strArray[ARRAY_SIZE];
decltype(strArray) &getRefToArray();

int main()
{
	return 0;
}