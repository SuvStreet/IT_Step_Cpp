#define PI 3.1415926535897932384626433832795
#include "Kolotysha_Triangle.h"
#include <iostream>
#include <cmath>
#include <exception>

Triangle::Triangle(const double a, const double b, const double c, size_t x) {
	
	if (a <= 0 || b <= 0 || c <= 0) {
		std::cout << "Такого треугольника не существует!!!\n";
	}

	if (x == 1) {
		if (b < 180 && c < 180) {
			sideA = a;
			angleB = b;
			angleC = c;
			angleA = 180 - (b + c);
			sideB = (a * sin(b * PI / 180)) / sin(angleA * PI / 180);
			sideC = sideB * sin(c * PI / 180) / sin(b * PI / 180);
		}
		else {
			std::cout << "Такого треугольника не существует!!!\n";
			sideA = 0;
			sideB = 0;
			sideC = 0;
			angleA = 0;
			angleB = 0;
			angleC = 0;
		}
	}

	if (x == 2) {
		if (c < 180) {
			sideA = a;
			sideB = b;
			angleC = c;
			sideC = a * a + b * b - 2 * a * b * cos(c * PI / 180);
			angleB = b * sin(c * PI / 180) / sideC;
			angleA = a * sin(angleB * PI / 180) / b;
			test(sideA, sideA, sideA);
		}
		else {
			std::cout << "Такого треугольника не существует!!!\n";
			sideA = 0;
			sideB = 0;
			sideC = 0;
			angleA = 0;
			angleB = 0;
			angleC = 0;
		}
	}

	if (x == 3) {
			sideA = a;
			sideB = b;
			sideC = c;
			angleA = acos((b * b + c * c - a * a) / 2 * b * c);
			angleB = acos((a * a + c * c - b * b) / 2 * a * c);
			angleC = 180 - (angleA + angleB);
	}

	if (test(sideA, sideB, sideC) != true) {
		std::cout << "Такого треугольника не существует!!!\n";
		sideA = 0;
		sideB = 0;
		sideC = 0;
		angleA = 0;
		angleB = 0;
		angleC = 0;
	}
}

bool Triangle::test(double sideA, double sideB, double sideC) {
	return sideA <= sideB + sideC;
}

double Triangle::getSideA() const {
	return sideA;
}

void Triangle::setSideA(const double newSideA) {
	sideA = newSideA;
}

double Triangle::getSideB() const {
	return sideB;
}

void Triangle::setSideB(const double newSideB) {
	sideB = newSideB;
}

double Triangle::getSideC() const {
	return sideC;
}

void Triangle::setSideC(const double newSideC) {
	sideC = newSideC;
}

double Triangle::getAngleA() const {
	return angleA;
}

void Triangle::setAngleA(const double newAngleA) {
	angleA = newAngleA;
}

double Triangle::getAngleB() const {
	return angleB;
}

void Triangle::setAngleB(const double newAngleB) {
	angleB = newAngleB;
}

double Triangle::getAngleC() const {
	return angleC;
}

void Triangle::setAngleC(const double newAngleC) {
	angleC = newAngleC;
}

double Triangle::getArea() {
	double p = (sideA + sideB + sideC) / 2;
	double S = sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
	if (S == 0) throw std::logic_error("Нельзя вычислить площадь не существующего треугольника!!!");
	return S;
}
