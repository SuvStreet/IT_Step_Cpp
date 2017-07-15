#include "Kolotysha_Square.h"
#include <iostream>
#include <exception>

Square::Square(const double a) {
	if (a > 0) {
		Rectangle::setSideA(a);
	}
	else std::cout << "Такого квадрата не существует!!!\n";
}

double Square::getSideA() const {
	return Rectangle::getSideA();
}

void Square::setSideA(const double newSideA) {
	Rectangle::setSideA(newSideA);
}

double Square::getArea() {
	double S = pow(Rectangle::getSideA(), 2);
	if (S == 0) throw std::logic_error("Нельзя вычислить площадь не существующего  квадрата!!!");
	return S;
}
