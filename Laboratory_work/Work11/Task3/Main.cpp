#include "MyVector.h"
#include<iostream>

void test()
{
	MyVector<double> a;

	for (size_t i = 0; i < 10; ++i){
		a.push_back(rand() % 11);
	}

	a.insert(17, 3);
	if (a.at(4) == 17)
		std::cout << "Test 1: OK!\n";
	else
		std::cout << "Test 1:Error!!!\n";

	a.resize(30);
	if (a.get_capacity() == 30)
		std::cout << "Test 2: OK!\n";
	else
		std::cout << "Test 2:Error!!!\n";

}

int main(int argc, char* argv[])
{

	test();
	return 0;
}
