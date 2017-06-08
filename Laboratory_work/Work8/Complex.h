#pragma once

#include<iostream>
#include<string>
#include<fstream>

class Complex
{
	double real = 0;
	double img = 0;
public:
	Complex() = default;
	Complex(const double a, const double b) : real(a), img(b) {}
	Complex(const Complex& myObj) : real(myObj.real), img(myObj.img) {}
	Complex& operator=(const Complex&);

	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);

	friend Complex& operator+=(Complex&, const Complex&);
	friend Complex& operator-=(Complex&, const Complex&);
	Complex& operator*=(const Complex&);
	friend Complex& operator/=(Complex&, const Complex&);

	friend std::ostream& operator<<(std::ostream& os, const Complex&);
	friend std::istream& operator>>(std::istream& is, Complex& com);

	~Complex() = default;
};
