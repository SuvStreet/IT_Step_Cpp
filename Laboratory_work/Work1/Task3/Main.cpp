#include "PrettyPrint.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::string a = "file", b = "write", c = "АБЖа_AppearAnce", d = "Madam I'm Adam";
	PrettyPrint x;

	std::cout << "Returning a string is a concatenation of two lines with a point between them." << std::endl;
	std::cout << "Before: " << a + " " + b << std::endl;
	std::cout << "After:  " << x.concatenate(a, b) << std::endl << std::endl;

	std::cout << "Replacing all letters a with o:" << std::endl;
	std::cout << "Before: " << c << std::endl;
	std::cout << "After: " << x.replace(c) << std::endl << std::endl;

	std::cout << "Words palindromes:" << std::endl;
	std::cout << "Before: " << d << std::endl;
	std::cout << "After: " << x.coup(d) << std::endl << std::endl;

	return 0;
}
