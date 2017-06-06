#include"Square.h"

void Square::setsideA(const int a)
{
	sideA = a;
}

void Square::setsideB(const int b)
{
	sideA = b;
}

int Square::getSquareArea(int a) const
{
	return pow(a, 2);
}

int Square::getSquareArea(int a, int b) const
{
	return a * b;
}

void Square::menu() {

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
				  int side;
				  bool x = false;
				  while (!x)
				  {
					  std::cout << "\nВведите значение стороны: ";
					  std::cin >> side;
					  setsideA(side);
					  if (side > 0)
					  {
						  x = true;
						  std::cout << "Площадь квадрата = " << getSquareArea(side) << std::endl;
					  }
					  else std::cout << "\nТакого квадрата не существует!!!\n";
				  }
				  break;
		}
		case 2:
		{
				  int sideA, sideB;
				  bool x = false;
				  while (!x)
				  {
					  std::cout << "\nВведите значение стороны a: ";
					  std::cin >> sideA;
					  setsideA(sideA);
					  std::cout << "Введите значение стороны b: ";
					  std::cin >> sideB;
					  setsideB(sideB);
					  if (sideA > 0 && sideB > 0 && sideA == sideB)
					  {
						  x = true;
						  std::cout << "Площадь квадрата = " << getSquareArea(sideA, sideB) << std::endl;
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
