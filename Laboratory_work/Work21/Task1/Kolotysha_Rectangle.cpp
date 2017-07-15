#include "Kolotysha_Rectangle.h"
#include <iostream>
#include <exception>

Rectangle::Rectangle(const double a, const double b) {
	if (a > 0 && b > 0) {
		Parallelogram::setSideA(a);
		Parallelogram::setSideB(b);
		Parallelogram::setAngleA(90);
	}
	else std::cout << "Такого прямоугольника не существует!!!\n";
}

double Rectangle::getSideA() const {
	return Parallelogram::getSideA();
}

void Rectangle::setSideA(const double newSideA) {
	Parallelogram::setSideA(newSideA);
}

double Rectangle::getSideB() const {
	return Parallelogram::getSideB();
}

void Rectangle::setSideB(const double newSideB) {
	Parallelogram::setSideB(newSideB);
}

double Rectangle::getArea() {
	double S = Parallelogram::getSideA() * Parallelogram::getSideB();
	if (S == 0) throw std::logic_error("Нельзя вычислить площадь не существующего  прямоугольника!!!");
	return S;
}
