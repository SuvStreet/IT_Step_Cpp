#include "Complex.h"

int main()
{
	Complex a;
	Complex b;
	std::cin >> a;
	std::cin >> b;

	/*std::cout << a * b << std::endl;
	std::cout << a << std::endl << std::endl;*/

	std::cout << a / b << std::endl;
	
	std::cout << (a /= b) << std::endl;

	return 0;
}
