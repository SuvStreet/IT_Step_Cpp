#include "Complex.h"

Complex& Complex::operator=(const Complex& newObj) {
	if (this == &newObj) {
		return *this;
	}
	real = newObj.real;
	img = newObj.img;
	return *this;
}

Complex operator+(const Complex& com1, const Complex& com2) {
	return Complex(com1.real + com2.real, com1.img + com2.img);
}

Complex operator-(const Complex& com1, const Complex& com2) {
	return Complex(com1.real - com2.real, com1.img - com2.img);
}

Complex operator*(const Complex& com1, const Complex& com2) {
	double z1 = ((com1.real * com2.real) - (com1.img * com2.img));
	double z2 = ((com1.img * com2.img) + (com1.real * com2.img));
	return Complex(z1, z2);
}

Complex operator/(const Complex& com1, const Complex& com2) {
	std::cout << com1.real << " " << com1.img;
	double q1 = ((com1.real * com2.real) + (com1.img * com2.img)) / ((com2.real * com2.real) + (com2.img * com2.img));
	std::cout << q1 << std::endl;
	double q2 = ((com2.real * com1.img) - (com1.real * com2.img)) / ((com2.real * com2.real) + (com2.img * com2.img));
	std::cout << q2 << std::endl;
	return Complex(q1, q2);
}

Complex& operator+=(Complex& com1, const Complex& com2)
{
	double a1 = com1.real += com2.real;
	double a2 = com1.img += com2.img;
	return Complex(a1, a2);
}

Complex& operator-=(Complex& com1, const Complex& com2)
{
	double a1 = com1.real -= com2.real;
	double a2 = com1.img -= com2.img;
	return Complex(a1, a2);
}

Complex& Complex::operator *= (const Complex& com)
{
	return *this = *this * com;
}

Complex& Complex::operator /= (const Complex& com)
{
	return *this = *this / com;
}

std::ostream& operator<<(std::ostream& os, const Complex& com) {
	os << com.real;
	if (com.img >= 0) { os << "+" << com.img << "i"; }
	else { os << com.img << "i"; }
	return os;
}

std::istream& operator >> (std::istream& is, Complex& com) {
	is >> com.real >> com.img;
	return is;
}
