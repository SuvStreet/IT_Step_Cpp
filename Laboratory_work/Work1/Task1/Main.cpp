#include "MyClass.h"

int main()
{
	Student Dima;

	Dima.init();

	setlocale(LC_ALL, "Russian");
	std::cout << "По вашим данным, я создала Вашу везитницу.";
	Dima.print();

	Dima.choice();

	return 0;
}
