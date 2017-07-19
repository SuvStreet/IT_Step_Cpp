#include"Square.h"
#include<iostream>

void menu();

int main()
{
	menu();
	return 0;
}

void menu() {

	Square square;
	setlocale(LC_ALL, "Russian");
	std::cout << "Вычисление площади квадрата!!!\n"
		"1. Через сторону.\n"
		"2. Через две стороны.\n"
		"0. Выход из программы." << std::endl;

	int choice;

	bool done = false;
	while (!done)
	{
		std::cout << "\nВаш выбор: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
				  double side;
				  bool x = false;
				  while (!x)
				  {
					  std::cout << "\nВведите значение стороны: ";
					  std::cin >> side;
					  square.setsideA(side);
					  if (side > 0)
					  {
						  x = true;
						  std::cout << "Площадь квадрата = " << square.squareArea(side) << std::endl;
					  }
					  else std::cout << "\nТакого квадрата не существует!!!\n";
				  }
				  break;
		}
		case 2:
		{
				  double sideA, sideB;
				  bool x = false;
				  while (!x)
				  {
					  std::cout << "\nВведите значение стороны a: ";
					  std::cin >> sideA;
					  square.setsideA(sideA);
					  std::cout << "Введите значение стороны b: ";
					  std::cin >> sideB;
					  square.setsideB(sideB);
					  if (sideA > 0 && sideB > 0 && sideA == sideB)
					  {
						  x = true;
						  std::cout << "Площадь квадрата = " << square.squareArea(sideA, sideB) << std::endl;
					  }
					  else std::cout << "\nТакого квадрата не существует!!!\n";
				  }
				  break;
		}
		case 0: std::cout << std::endl;
			done = true;
			break;
		default: std::cout << "\nНет такого пункта в меню!!!\n";
		}
	}
}
