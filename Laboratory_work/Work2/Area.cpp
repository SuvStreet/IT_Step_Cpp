#include "Area.h"

void Area::setsideA(const int a)
{
	sideA = a;
}

void Area::setsideB(const int b)
{
	sideB = b;
}

void Area::setheight(const int newheight)
{
	height = newheight;
}

void Area::setdiagonalA(const int newdiagonalA)
{
	diagonalA = newdiagonalA;
}

void Area::setdiagonalB(const int newdiagonalB)
{
	diagonalB = newdiagonalB;
}

void Area::setangle(const double newangle)
{
	angle = newangle;
}

int Area::getRectangleArea(int sideA, int sideB){
	counter++;
	return sideA * sideB;
}

int Area::getRectangleArea(int sideA){
	counter++;
	return pow(sideA, 2);
}

int Area::getParallelogramArea(int sideA, int height){
	counter++;
	return sideA * height;
}

double Area::getParallelogramArea(int sideA, int sideB, double angle){
	counter++;
	return sideA * sideB * sin(angle * PI / 180);
}

double Area::getRhombusArea(int sideA, double angle){
	counter++;
	return pow(sideA, 2) * sin(angle * PI / 180);
}

double Area::getRhombusArea(int diagonalA, int diagonalB){
	counter++;
	return 0.5 * diagonalA * diagonalB;
}

void Area::menu() {

	setlocale(LC_ALL, "Russian");
	std::cout << "Подсчет площади геометрических фигур!!!\n"
		"1. Прямоугольник.\n"
		"2. Параллелограмм.\n"
		"3. Ромб.\n"
		"0. Выход из программы." << std::endl;

	int choice, newChoice;
	std::cout << "\nВаш выбор: ";
	std::cin >> choice;

	bool done = false;
	while (!done)
	{
		switch (choice)
		{
		case 1:
		{
				  std::cout << "\nПрямоугольник:\n"
					  "1. Через две стороны."
					  "2. Через одну сторону (при условии, что вторая сторона равна первой.).";
				  std::cin >> newChoice;
				  if (newChoice == 1)
				  {
					  bool x = false;
					  while (!x){
						  std::cout << "\nВведите значение стороны a: ";
						  std::cin >> sideA;
						  setsideA(sideA);
						  std::cout << "Введите значение стороны b: ";
						  std::cin >> sideB;
						  setsideB(sideB);
						  if (sideA > 0 && sideB > 0)
						  {
							  x = true;
							  std::cout << "\nПлощадь прямоугольника = " << getRectangleArea(sideA, sideB) << std::endl;
						  }
						  else std::cout << "\nТакого прямоугольника не существует!!!\n";
					  }
				  }
				  if (newChoice == 2)
				  {
					  bool x = false;
					  while (!x){
						  std::cout << "\nВведите значение сторон: ";
						  std::cin >> sideA;
						  setsideA(sideA);
						  if (sideA > 0)
						  {
							  x = true;
							  std::cout << "\nПлощадь прямоугольника = " << getRectangleArea(sideA) << std::endl;
						  }
						  else std::cout << "\nТакого прямоугольника не существует!!!\n";
					  }
				  }
				  break;
		}
		case 2:
		{
				  std::cout << "\nПараллелограмм:\n"
					  "1. Через основание и высоту."
					  "2. Через две стороны и угол между ними.";
				  std::cin >> newChoice;
				  if (newChoice == 1)
				  {
					  bool x = false;
					  while (!x){
						  std::cout << "\nВведите значение стороны a: ";
						  std::cin >> sideA;
						  setsideA(sideA);
						  std::cout << "Введите значение высоты: ";
						  std::cin >> height;
						  setsideB(height);
						  if (sideA > 0 && height > 0)
						  {
							  x = true;
							  std::cout << "\nПлощадь параллелограмма = " << getParallelogramArea(sideA, height) << std::endl;
						  }
						  else std::cout << "\nТакого параллелограмма не существует!!!\n";
					  }
				  }
				  if (newChoice == 2)
				  {
					  bool x = false;
					  while (!x){
						  std::cout << "\nВведите значение стороны a: ";
						  std::cin >> sideA;
						  setsideA(sideA);
						  std::cout << "\nВведите значение стороны b: ";
						  std::cin >> sideB;
						  setsideA(sideB);
						  std::cout << "\nВведите значение угла между стороной a и b: ";
						  std::cin >> angle;
						  setangle(angle);
						  if (sideA > 0 && sideA > 0 && angle < 180 && angle > 0)
						  {
							  x = true;
							  std::cout << "\nПлощадь параллелограмма = " << getParallelogramArea(sideA, sideB, angle) << std::endl;
						  }
						  else std::cout << "\nТакого параллелограмма не существует!!!\n";
					  }
				  }
				  break;
		}
		case 3:
		{
				  std::cout << "\nРомб:\n"
					  "1. Через основание и высоту."
					  "2. Через две стороны и угол между ними.";
				  std::cin >> newChoice;
				  if (newChoice == 1)
				  {
					  bool x = false;
					  while (!x){
						  std::cout << "\nВведите значение стороны a: ";
						  std::cin >> sideA;
						  setsideA(sideA);
						  std::cout << "Введите значение угла: ";
						  std::cin >> angle;
						  setsideB(angle);
						  if (sideA > 0 && angle > 0 && angle < 180)
						  {
							  x = true;
							  std::cout << "\nПлощадь параллелограмма = " << getRhombusArea(sideA, height) << std::endl;
						  }
						  else std::cout << "\nТакого параллелограмма не существует!!!\n";
					  }
				  }
				  if (newChoice == 2)
				  {
					  bool x = false;
					  while (!x){
						  std::cout << "\nВведите значение стороны a: ";
						  std::cin >> sideA;
						  setsideA(sideA);
						  std::cout << "\nВведите значение стороны b: ";
						  std::cin >> sideB;
						  setsideA(sideB);
						  std::cout << "Введите значение угла: ";
						  std::cin >> angle;
						  setsideB(angle);
						  if (sideA > 0 && sideB > 0 && angle > 0 && angle < 180)
						  {
							  x = true;
							  std::cout << "\nПлощадь параллелограмма = " << getRhombusArea(sideA, height) << std::endl;
						  }
						  else std::cout << "\nТакого параллелограмма не существует!!!\n";
					  }
				  }
				  break;
		}
		case 0: std::cout << std::endl;
			done = true;
			break;
		default: std::cout << "\nНет такого пункта в меню!!!\n";
		}
	}

	std::cout << "Вы посчитали площадь " << Area::getCounter() << " раз";
}
