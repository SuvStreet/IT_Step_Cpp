#include <iostream>
#include "Kolotysha_Triangle.h"
#include "Kolotysha_Parallelogram.h"
#include "Kolotysha_Rectangle.h"
#include "Kolotysha_Square.h"
#include "Kolotysha_Circle.h"

template<typename T>
void exception(T a) {
	try {
		std::cout << a.getArea() << std::endl;
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	std::cout << "\nТреугольник\n" << std::endl;
	Triangle a(15, 180, 40, 1);
	exception(a);

	std::cout << "\nПараллелограмм\n" << std::endl;
	Parallelogram b(15, 30, 180);
	exception(b);

	std::cout << "\nПрямоугольник\n" << std::endl;
	Rectangle c(15, -30);
	exception(c);

	std::cout << "\nКвадрат\n" << std::endl;
	Square d(-15);
	exception(d);

	std::cout << "\nКруг\n" << std::endl;
	Circle e(15, 20, -10);
	exception(e);

	std::cout << std::endl;

	return 0;
}
