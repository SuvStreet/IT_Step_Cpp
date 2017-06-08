#include "Complex.h"

int main()
{
	Complex a;
	Complex b;
	std::cin >> a;
	std::cin >> b;

	std::cout << a * b << std::endl;
	a *= b;
	std::cout << a << std::endl;

	return 0;
}
