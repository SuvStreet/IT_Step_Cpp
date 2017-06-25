#include "Digit.h"

size_t Digit::counter = 0;

Digit::Digit() : digit(0) { ++counter; }
Digit::Digit(const int x) : digit(x) { ++counter; }
Digit::Digit(const double x) : digit(x) { ++counter; }

Digit::Digit(const Digit& myObj) : digit(myObj.digit) { ++counter; }
Digit::Digit(Digit&& myObj) : digit(myObj.digit) {
	myObj.digit = 0;
	++counter;
}

int Digit::getDigit() const {
	return digit;
}

void Digit::setDigit(const int x) {
	digit = x;
}

Digit Digit::operator-() {
	Digit temp;
	temp.digit = -digit;
	return temp;
}

Digit Digit::operator+(const Digit& newDigit) {
	Digit temp = *this;
	temp += newDigit.digit;
	return temp;
}

Digit Digit::operator+(const int newDigit) {
	Digit temp = *this;
	temp += newDigit;
	return temp;
}

Digit Digit::operator-(const Digit& newDigit) {
	Digit temp = *this;
	temp -= newDigit.digit;
	return temp;
}

Digit Digit::operator-(const int newDigit) {
	Digit temp = *this;
	temp -= newDigit;
	return temp;
}

Digit Digit::operator*(const Digit& newDigit) {
	Digit temp = *this;
	temp *= newDigit.digit;
	return temp;
}

Digit Digit::operator*(const int newDigit) {
	Digit temp = *this;
	temp *= newDigit;
	return temp;
}

Digit Digit::operator/(const Digit& newDigit) {
	Digit temp = *this;
	temp /= newDigit.digit;
	return temp;
}

Digit Digit::operator/(const int newDigit) {
	Digit temp = *this;
	temp /= newDigit;
	return temp;
}

Digit Digit::operator%(const Digit& newDigit) {
	Digit temp = *this;
	temp %= newDigit.digit;
	return temp;
}

Digit Digit::operator%(const int newDigit) {
	Digit temp = *this;
	temp %= newDigit;
	return temp;
}

bool Digit::operator>(const Digit& newDigit) {
	return digit > newDigit.digit;
}

bool Digit::operator>(const int newDigit) {
	return digit > newDigit;
}

bool Digit::operator<(const Digit& newDigit) {
	return digit < newDigit.digit;
}

bool Digit::operator<(const int newDigit) {
	return digit < newDigit;
}

bool Digit::operator==(const Digit& newDigit) {
	return digit == newDigit.digit;
}

bool Digit::operator==(const int newDigit) {
	return digit == newDigit;
}

bool Digit::operator!=(const Digit& newDigit) {
	return digit != newDigit.digit;
}

bool Digit::operator!=(const int newDigit) {
	return digit != newDigit;
}

bool Digit::operator>=(const Digit& newDigit) {
	return digit >= newDigit.digit;
}

bool Digit::operator>=(const int newDigit) {
	return digit >= newDigit;
}

bool Digit::operator<=(const Digit& newDigit) {
	return digit <= newDigit.digit;
}

bool Digit::operator<=(const int newDigit) {
	return digit <= newDigit;
}

Digit& Digit::operator++() {
	++digit;
	return *this;
}

Digit Digit::operator++(int) {
	Digit temp = *this;
	++digit;
	return temp;
}

Digit& Digit::operator--() {
	--digit;
	return *this;
}

Digit Digit::operator--(int) {
	Digit temp = *this;
	--digit;
	return temp;
}

Digit& Digit::operator=(const Digit& obj) {
	if (this == &obj) {
		return *this;
	}
	digit = obj.digit;
	return *this;
}

Digit& Digit::operator=(Digit&& obj) {
	if (this == &obj) {
		return *this;
	}
	digit = obj.digit;
	obj.digit = 0;
	return *this;
}

Digit& Digit::operator+=(const Digit& myObj) {
	digit += myObj.digit;
	return *this;
}

Digit& Digit::operator+=(const int myObj) {
	digit += myObj;
	return *this;
}

Digit& Digit::operator-=(const Digit& myObj) {
	digit -= myObj.digit;
	return *this;
}

Digit& Digit::operator-=(const int myObj) {
	digit -= myObj;
	return *this;
}

Digit& Digit::operator*=(const Digit& myObj) {
	digit *= myObj.digit;
	return *this;
}

Digit& Digit::operator*=(const int myObj) {
	digit *= myObj;
	return *this;
}

Digit& Digit::operator/=(const Digit& myObj) {
	digit /= myObj.digit;
	return *this;
}

Digit& Digit::operator/=(const int myObj) {
	digit /= myObj;
	return *this;
}

Digit& Digit::operator%=(const Digit& myObj) {
	digit %= myObj.digit;
	return *this;
}

Digit& Digit::operator%=(const int myObj) {
	digit %= myObj;
	return *this;
}

Digit::operator int() const {
	return digit;
}

Digit::operator double() const {
	return digit;
}

void Digit::operator()(const int i) {
	digit = i;
}

std::ostream& operator<<(std::ostream& os, const Digit& a) {
	os << a.digit;
	return os;
}

std::istream& operator >> (std::istream& is, Digit& a) {
	int temp;
	is >> temp;
	a.setDigit(temp);
	return is;
}
