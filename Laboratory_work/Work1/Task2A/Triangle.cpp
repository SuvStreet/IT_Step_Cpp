#include"Triangle.h"

void Triangle::setsideA(const int a)
{
	sideA = a;
}

void Triangle::setsideB(const int b)
{
	sideA = b;
}

void Triangle::setsideC(const int c)
{
	sideA = c;
}

void Triangle::setbase(const int newbase)
{
	base = newbase;
}
void Triangle::setheight(const int newheight)
{
	height = newheight;
}
void Triangle::setangle(const float newangle)
{
	angle = newangle;
}

int Triangle::getTriangleArea(int base, int height) const
{
	return 0.5 * base * height;
}

float Triangle::getTriangleArea(int sideA, int sideB, float angle) const
{
	return sin(angle * PI / 180) * 0.5 * sideA * sideB;
}

float Triangle::getTriangleArea(int sideA, int sideB, int sideC) const
{
	float p = (sideA + sideB + sideC) / 2;
	float S = sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
	return S;
}

void Triangle::menu() {

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
					  setbase(base);
					  std::cout << "Введите значение высоты: ";
					  std::cin >> height;
					  setheight(height);
					  if (base > 0 && height > 0)
					  {
						  x = true;
						  std::cout << "Площадь треугольника = " << getTriangleArea(base, height) << std::endl;
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
					  setsideA(sideA);
					  std::cout << "Введите значение стороны b: ";
					  std::cin >> sideB;
					  setsideB(sideB);
					  std::cout << "Введите угол между стороной a и b: ";
					  std::cin >> angle;
					  setangle(angle);
					  if (sideA > 0 && sideB > 0 && angle > 0 && angle < 180)
					  {
						  x = true;
						  std::cout << "Площадь треугольника = " << getTriangleArea(sideA, sideB, angle) << std::endl;
					  }
					  else std::cout << "\nТакого треугольника не существует!!!\n";
				  }
				  break;
		}
		case 3:
		{

				  int sideA, sideB, sideC;
				  bool x = false;
				  while (!x)
				  {
					  std::cout << "\nВведите значение стороны a: ";
					  std::cin >> sideA;
					  setsideA(sideA);
					  std::cout << "Введите значение стороны b: ";
					  std::cin >> sideB;
					  setsideB(sideB);
					  std::cout << "Введите значение стороны c: ";
					  std::cin >> sideC;
					  setsideC(sideC);
					  if (sideA > 0 && sideB > 0 && sideC > 0 && getTriangleArea(sideA, sideB, sideC) > 0)
					  {
						  x = true;
						  std::cout << "Площадь треугольника = " << getTriangleArea(sideA, sideB, sideC) << std::endl;
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
