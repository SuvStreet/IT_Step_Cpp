#include"PrettyPrint.h"

int main()
{
	std::string a = "file", b = "write", c = "appearance", d = "Madam I'm Adam";
	PrettyPrint x;

	std::cout << "Returning a string is a concatenation of two lines with a point between them." << std::endl;
	std::cout << "Before: " << a + " " + b << std::endl;
	std::cout << "After: " << x.concatenation(a, b) << std::endl << std::endl;

	std::cout << "Replacing all letters a with o:" << std::endl;
	std::cout << "Before: " << c << std::endl;
	std::cout << "After: " << x.substitution(c) << std::endl << std::endl;

	std::cout << "Words palindromes:" << std::endl;
	std::cout << "Before: " << d << std::endl;
	x.coup(&d);
	std::cout << "After: " << d << std::endl << std::endl;

	return 0;
}
