#include"Circle.h"

#include<iostream>

void test()
{
	int x = 15;
	Circle a(10, 10, x);

	a++;
	if (a.getRadius() - x == 1)
		std::cout << "Test 1: OK" << std::endl;
	else std::cout << "Test 1: Error!!!\n";

	Circle b(10, 10, x + 1);
	if (a == b)
		std::cout << "Test 2: OK" << std::endl;
	else std::cout << "Test 2: Error!!!\n";

	++a;
	if (a > b)
		std::cout << "Test 3: OK" << std::endl;
	else std::cout << "Test 3: Error!!!\n";

	if (b < a)
		std::cout << "Test 4: OK" << std::endl;
	else std::cout << "Test 4: Error!!!\n";

	Circle c(10, 10, x + 1);
	if (b == c)
		std::cout << "Test 5: OK" << std::endl;
	else std::cout << "Test 5: Error!!!\n";

	Circle d(20, 30, 27);
	if (b != d)
		std::cout << "Test 6: OK" << std::endl;
	else std::cout << "Test 6: Error!!!\n";
	Circle rad(20, 30, 15);

	if (rad.getAreaCircle() - 706.858 < 0.001)
		std::cout << "Test 7: OK" << std::endl;
	else std::cout << "Test 7: Error!!!\n";

	if (rad.getLengthCircle() - 94.24778 < 0.001)
		std::cout << "Test 8: OK" << std::endl;
	else std::cout << "Test 8: Error!!!\n";

}

int main()
{
	test();
	return 0;
}
