#define PI 3.1415926535897932384626433832795
#include "Kolotysha_Circle.h"
#include <iostream>
#include <exception>

Circle::Circle(const double a) {
	if (a > 0) {
		radius = a;
	}
	else std::cout << "Такого круга не существует!!!\n";
}

double Circle::getSideA() const {
	return radius;
}

void Circle::setSideA(const double newRadius) {
	radius = newRadius;
}

double Circle::getArea() {
	double S = PI * pow(radius, 2);
	if (S == 0) throw std::logic_error("Нельзя вычислить площадь не существующего круга!!!");
	return S;
}
