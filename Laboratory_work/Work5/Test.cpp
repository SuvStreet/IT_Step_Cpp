#include "Digit.h"
#include "Test.h"
#include <iostream>

void Test::test() {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}

void Test::printResForTest1(const Digit& d, const int value, const int counter) {
	if (d.getDigit() == value && Digit::getCounter() == counter){
		std::cout << "\tOK" << std::endl;
	}
	else { std::cout << "\tError" << std::endl; }
}

void Test::printResForTest2(const Digit d, const int res) {
	if (d.getDigit() == res){
		std::cout << "\tOK" << std::endl;
	}
	else { std::cout << "\tError" << std::endl; }
}

void Test::printResForTest4(bool x, bool y) {
	if (x == y){
		std::cout << "\tOK" << std::endl;
	}
	else { std::cout << "\tError" << std::endl; }
}

void Test::test1() {
	std::cout << "Test 1: " << std::endl;
	Digit d1;
	printResForTest1(d1, 0, 1);

	Digit d2(10);
	printResForTest1(d2, 10, 2);

	Digit d3(15.7);
	printResForTest1(d3, 15, 3);

	Digit d4 = d3;
	printResForTest1(d4, 15, 4);

	Digit d5 = std::move(d4);
	printResForTest1(d5, 15, 5);
	printResForTest1(d4, 0, 5);
	std::cout << std::endl;
}

void Test::test2() {
	std::cout << "Test 2: " << std::endl;
	const int x = 10;
	const int y = 5;
	Digit d1(x);
	Digit d2(y);
	printResForTest2(-d1, -x);
	printResForTest2(d1 + d2, x + y);
	printResForTest2(d1 * d2, x * y);
	printResForTest2(d1 - d2, x - y);
	printResForTest2(d2 - d1, y - x);
	printResForTest2(d1 / d2, x / y);
	printResForTest2(d1 % d2, x % y);
	std::cout << std::endl;
}

void Test::test3() {
	std::cout << "Test 3: " << std::endl;
	const int x = 28;
	const int y = 2;
	Digit d1(x);
	printResForTest2(d1 + y, x + y);
	printResForTest2(d1 - y, x - y);
	printResForTest2(d1 * y, x * y);
	printResForTest2(d1 / y, x / y);
	printResForTest2(d1 % y, x % y);
	std::cout << std::endl;
}

void Test::test4() {
	std::cout << "Test 4: " << std::endl;
	const int x = 100;
	const int y = -100;
	Digit d1(x);
	Digit d2(y);
	printResForTest4(d1 > d2, x > y);
	printResForTest4(d1 < d2, x < y);
	printResForTest4(d1 == d2, x == y);
	printResForTest4(d1 != d2, x != y);
	printResForTest4(d1 == d1, x == x);
	printResForTest4(d2 > d1, y > x);
	printResForTest4(d1 >= d1, x >= x);
	printResForTest4(d2 >= d1, y >= x);
	printResForTest4(d2 <= d1, y <= x);
	std::cout << std::endl;
}

void Test::test5() {
	std::cout << "Test 5: " << std::endl;
	int x = 10;
	Digit d1(x);
	printResForTest2(++d1, ++x);
	printResForTest2((++(++(++d1))), (++(++(++x))));
	printResForTest2(--d1, --x);
	printResForTest2((--(--(--d1))), (--(--(--x))));

	x = 4;
	Digit d2(x);
	printResForTest2(d2++, x++);
	printResForTest2(d2--, x--);
	std::cout << std::endl;
}

void Test::test6(){
	std::cout << "Test 6: " << std::endl;
	const int x = 10;
	const int y = 12;
	Digit d1(x);
	Digit d2(y);

	d1 = d2;
	printResForTest2(d1, y);

	d2 = d1;
	printResForTest2(d2, y);

	d1 = std::move(d2);
	printResForTest2(d1, y);
	printResForTest2(d2, 0);

	Digit d3(18);
	d2 = d3;
	printResForTest2(d2, 18);

	d1 = d2 = d3;
	printResForTest2(d1, 18);

	std::cout << std::endl;
}
