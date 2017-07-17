#include "Student.h"
#include <iostream>

int main()
{
	Student Dima;

	Dima.init();

	std::cout << "According to your information, a business card was created."; // Согласно вашей информации, была создана визитная карточка
	Dima.print();

	Dima.choice();

	return 0;
}
