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

Digit Digit::operator+(const Digit& newDigit) const {
	return Digit(digit + newDigit.digit);

	// Digit temp; создаём временный объект
	// temp.digit = digit + newDigit.digit; присваеваем правильное значение полю временного объекта
	// return temp; возвращаем времменный объект
}

Digit Digit::operator+(const int newDigit) const { // перегрузка оператора перегрузки
	return Digit(digit + newDigit);

	// Digit temp; создаём временный объект
	// temp.digit = digit + newDigit; присваеваем правильное значение полю временного объекта
	// return temp; возвращаем времменный объект
}

Digit operator+(const int a, const Digit& b) {
	return Digit(a + b.digit);
}

Digit Digit::operator-(const Digit& newDigit) const {
	return Digit(digit - newDigit.digit);
}

Digit Digit::operator-(const int newDigit) const {
	return Digit(digit - newDigit);
}

Digit operator-(const int a, const Digit& b) {
	return Digit(a - b.digit);
}

Digit Digit::operator*(const Digit& newDigit) const {
	return Digit(digit * newDigit.digit);
}

Digit Digit::operator*(const int newDigit) const {
	return Digit(digit * newDigit);
}

Digit operator*(const int a, const Digit& b) {
	return Digit(a * b.digit);
}

Digit Digit::operator/(const Digit& newDigit) const {
	return Digit(digit / newDigit.digit);
}

Digit Digit::operator/(const int newDigit) const {
	return Digit(digit / newDigit);
}

Digit operator/(const int a, const Digit& b) {
	return Digit(a / b.digit);
}

Digit Digit::operator%(const Digit& newDigit) const {
	return Digit(digit % newDigit.digit);
}

Digit Digit::operator%(const int newDigit) const {
	return Digit(digit % newDigit);
}

Digit operator%(const int a, const Digit& b) {
	return Digit(a % b.digit);
}

bool Digit::operator>(const Digit& newDigit) const { // перегрузка bool
	return digit > newDigit.digit;
}

bool Digit::operator>(const int newDigit) const {
	return !(*this > newDigit);
}

bool Digit::operator<(const Digit& newDigit) const {
	return digit < newDigit.digit;
}

bool Digit::operator<(const int newDigit) const { // перегрузка оператора перегрузки bool
	return !(*this < newDigit);
}

bool Digit::operator==(const Digit& newDigit) const {
	return digit == newDigit.digit;
}

bool Digit::operator==(const int newDigit) const {
	return !(*this == newDigit);
}

bool Digit::operator!=(const Digit& newDigit) const {
	return digit != newDigit.digit;
}

bool Digit::operator!=(const int newDigit) const {
	return !(*this != newDigit);
}

bool Digit::operator>=(const Digit& newDigit) const {
	return digit >= newDigit.digit;
}

bool Digit::operator>=(const int newDigit) const {
	return !(*this >= newDigit);
}

bool Digit::operator<=(const Digit& newDigit) const {
	return digit <= newDigit.digit;
}

bool Digit::operator<=(const int newDigit) const {
	return !(*this <= newDigit);
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
