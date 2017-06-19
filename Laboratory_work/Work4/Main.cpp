#include "Test.h"
#include "MyVector.h"
#include<iostream>

int main(int argc, char* argv[])
{
	double array[30];
	for (int i = 0; i < 30; ++i)
	{
		array[i] = rand() % 11;
	}

	MyVector a(array, 10);
	MyVector b;

	std::cout << "Array: ";
	a.print();
	a.sort();
	std::cout << "\nSorted array: ";
	a.print();
	std::cout << "\n";

	Test t;
	t.test();
	std::cout << "\n";

	std::cout << "The number of created vectors: " << a.getCounterVector() << "\n";
	std::cout << "The number of vectors existing in the present time of program execution: " << a.getCounterRealVector() << "\n" << std::endl;

	return 0;
}
