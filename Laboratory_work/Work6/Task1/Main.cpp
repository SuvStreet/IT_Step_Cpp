#include "Digit.h"

int main(){
	
	Digit d1(10);
	Digit d2(20);

	d1 += 333;
	std::cout << d1 << std::endl;
	d1 += d2;
	std::cout << d1 << std::endl;

	d1 -= 100;
	std::cout << d1 << std::endl;
	d1 -= d2;
	std::cout << d1 << std::endl;

	d1 *= 3;
	std::cout << d1 << std::endl;
	d1 *= d2;
	std::cout << d1 << std::endl;

	d1 /= 3;
	std::cout << d1 << std::endl;
	d1 /= d2;
	std::cout << d1 << std::endl;

	d1 %= 33;
	std::cout << d1 << std::endl;
	d1 %= d2;
	std::cout << d1 << std::endl;

	std::cout << std::endl;
	std::cout << d1 + d1 << std::endl;
	std::cout << d1 << std::endl;

	return 0;
}
