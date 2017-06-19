#pragma once

class Digit
{
	int digit;
	static size_t counter;
public:
	Digit();
	explicit Digit(const int);
	explicit Digit(const double);
	~Digit() {}

	Digit(const Digit&);
	Digit(Digit&&);

	int getDigit() const;
	void setDigit(const int);
	int getCounter() const;

	Digit operator-();

	Digit operator+(const Digit&);
	Digit operator+(const int);

	Digit operator-(const Digit&);
	Digit operator-(const int);

	Digit operator*(const Digit&);
	Digit operator*(const int);

	Digit operator/(const Digit&);
	Digit operator/(const int);

	Digit operator%(const Digit&);
	Digit operator%(const int);

	bool operator>(const Digit&);
	bool operator>(const int);

	bool operator<(const Digit&);
	bool operator<(const int);

	bool operator==(const Digit&);
	bool operator==(const int);

	bool operator!=(const Digit&);
	bool operator!=(const int);

	bool operator>=(const Digit&);
	bool operator>=(const int);

	bool operator<=(const Digit&);
	bool operator<=(const int);

	Digit& operator++();
	Digit operator++(int);

	Digit& operator--();
	Digit operator--(int);

	Digit& operator=(const Digit&);
	Digit& operator=(Digit&&);
};
