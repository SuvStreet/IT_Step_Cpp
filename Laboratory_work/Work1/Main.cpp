#include "MyClass.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	
	Student Dima;

	std::cout << "Привествую Вас. Я результат вашей первой лабораторной работы.\n";
	std::cout << "Пожалуйста введите свои данные которые я попрашу.\nХочу обратить Ваше внимание,\
 изменять Фамилию, Имя, Отчество и год вашего рождения, далее будет нельзя!\n\n";

	Dima.init();

	setlocale(LC_ALL, "Russian");
	std::cout << "\nПо вашим данным введённым выше, я создала Вашу везитницу.";
	Dima.print();

	Dima.choice();

	return 0;
}
