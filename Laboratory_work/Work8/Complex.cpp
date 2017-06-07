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
	double q1 = (((com1.real * com2.real) + (com1.img * com2.img)) / (pow(com2.real, 2) + pow(com2.img, 2)));
	double q2 = (((com2.real * com1.img) - (com1.real * com2.img)) / (pow(com2.real, 2) + pow(com2.img, 2)));
	return Complex(q1, q2);
}

Complex& operator+=(Complex& com1, const Complex& com2)
{
	com1.real += com2.real;
	return com1;
}

std::ostream& operator<<(std::ostream& os, const Complex& com) {
	os << com.real;
	if (com.real > 0) { os << " + " << com.img; }
	else { os << com.img << "i";  }
	return os;
}


//std::istream& operator >> (std::istream& is, Complex& a) {
//	int real, img;
//	is >> real >> img;
//	return Complex(real, img);
//}
