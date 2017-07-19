#include"Triangle.h"
#include<iostream>

void menu();

int main() {
	menu();
	return 0;
}

void menu() {

	Triangle triangle;
	setlocale(LC_ALL, "Russian");
	std::cout << "Вычисление площади треугольника!!!\n"
		"1. Через основание и высоту.\n"
		"2. Через стороны и угол.\n"
		"3. Через формулу Герона.\n"
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
				  int base, height;
				  bool x = false;
				  while (!x)
				  {
					  std::cout << "\nВведите значение основания: ";
					  std::cin >> base;
					  triangle.setbase(base);
					  std::cout << "Введите значение высоты: ";
					  std::cin >> height;
					  triangle.setheight(height);
					  if (base > 0 && height > 0)
					  {
						  x = true;
						  std::cout << "Площадь треугольника = " << triangle.getTriangleArea(base, height) << std::endl;
					  }
					  else std::cout << "\nТакого треугольника не существует!!!\n";
				  }
				  break;
		}
		case 2:
		{
				  int sideA, sideB;
				  float angle;
				  bool x = false;
				  while (!x)
				  {
					  std::cout << "\nВведите значение стороны a: ";
					  std::cin >> sideA;
					  triangle.setsideA(sideA);
					  std::cout << "Введите значение стороны b: ";
					  std::cin >> sideB;
					  triangle.setsideB(sideB);
					  std::cout << "Введите угол между стороной a и b: ";
					  std::cin >> angle;
					  triangle.setangle(angle);
					  if (sideA > 0 && sideB > 0 && angle > 0 && angle < 180)
					  {
						  x = true;
						  std::cout << "Площадь треугольника = " << triangle.getTriangleArea(sideA, sideB, angle) << std::endl;
					  }
					  else std::cout << "\nТакого треугольника не существует!!!\n";
				  }
				  break;
		}
		case 3:
		{

				  double sideA, sideB, sideC;
				  bool x = false;
				  while (!x)
				  {
					  std::cout << "\nВведите значение стороны a: ";
					  std::cin >> sideA;
					  triangle.setsideA(sideA);
					  std::cout << "Введите значение стороны b: ";
					  std::cin >> sideB;
					  triangle.setsideB(sideB);
					  std::cout << "Введите значение стороны c: ";
					  std::cin >> sideC;
					  triangle.setsideC(sideC);
					  if (sideA > 0 && sideB > 0 && sideC > 0 && triangle.getTriangleArea(sideA, sideB, sideC) > 0)
					  {
						  x = true;
						  std::cout << "Площадь треугольника = " << triangle.getTriangleArea(sideA, sideB, sideC) << std::endl;
					  }
					  else std::cout << "\nТакого треугольника не существует!!!\n";
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
