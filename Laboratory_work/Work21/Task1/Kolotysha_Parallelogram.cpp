#define PI 3.1415926535897932384626433832795
#include "Kolotysha_Parallelogram.h"
#include <iostream>
#include <cmath>
#include <exception>

Parallelogram::Parallelogram(const double a, const double b, const double c) {

	if (a > 0 && b > 0 && c > 0 && c < 180) {
		sideA = a;
		sideB = b;
		angleA = c;
	}
	else std::cout << "Такого параллелограмма не существует!!!\n";
}

double Parallelogram::getSideA() const {
	return sideA;
}

void Parallelogram::setSideA(const double newSideA) {
	sideA = newSideA;
}

double Parallelogram::getSideB() const {
	return sideB;
}

void Parallelogram::setSideB(const double newSideB) {
	sideB = newSideB;
}

double Parallelogram::getAngleA() const {
	return angleA;
}

void Parallelogram::setAngleA(const double newAngleA) {
	angleA = newAngleA;
}

double Parallelogram::getArea() {
	double S = sideA * sideB * sin(angleA * PI / 180);
	if (S == 0) throw std::logic_error("Нельзя вычислить площадь не существующего параллелограмма!!!");
	return S;
}
