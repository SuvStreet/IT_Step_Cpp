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

int Digit::getCounter() const {
	return counter;
}

Digit Digit::operator-() {
	Digit temp;
	temp.digit = -digit;
	return temp;
}

Digit Digit::operator+(const Digit& newDigit) {
	Digit temp; // создаём временный объект
	temp.digit = digit + newDigit.digit; // присваеваем правильное значение полю временного объекта
	return temp; // возвращаем времменный объект
}

Digit Digit::operator+(const int newDigit) { // перегрузка оператора перегрузки
	Digit temp; // создаём временный объект
	temp.digit = digit + newDigit; // присваеваем правильное значение полю временного объекта
	return temp; // возвращаем времменный объект
}

Digit Digit::operator-(const Digit& newDigit) {
	Digit temp;
	temp.digit = digit - newDigit.digit;
	return temp;
}

Digit Digit::operator-(const int newDigit) {
	Digit temp;
	temp.digit = digit - newDigit;
	return temp;
}

Digit Digit::operator*(const Digit& newDigit) {
	Digit temp;
	temp.digit = digit * newDigit.digit;
	return temp;
}

Digit Digit::operator*(const int newDigit) {
	Digit temp;
	temp.digit = digit * newDigit;
	return temp;
}

Digit Digit::operator/(const Digit& newDigit) {
	Digit temp;
	temp.digit = digit / newDigit.digit;
	return temp;
}

Digit Digit::operator/(const int newDigit) {
	Digit temp;
	temp.digit = digit / newDigit;
	return temp;
}

Digit Digit::operator%(const Digit& newDigit) {
	Digit temp;
	temp.digit = digit % newDigit.digit;
	return temp;
}

Digit Digit::operator%(const int newDigit) {
	Digit temp;
	temp.digit = digit % newDigit;
	return temp;
}

bool Digit::operator>(const Digit& newDigit) { // перегрузка bool
	return digit > newDigit.digit;
}

bool Digit::operator>(const int newDigit) {
	return digit > newDigit;
}

bool Digit::operator<(const Digit& newDigit) {
	return digit < newDigit.digit;
}

bool Digit::operator<(const int newDigit) { // перегрузка оператора перегрузки bool
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
