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

	static int getCounter() {
		return counter;
	}

	Digit operator-();

	Digit operator+(const Digit&) const;
	Digit operator+(const int) const;
	friend Digit operator+(const int, const Digit&);

	Digit operator-(const Digit&) const;
	Digit operator-(const int) const;
	friend Digit operator-(const int, const Digit&);

	Digit operator*(const Digit&) const;
	Digit operator*(const int) const;
	friend Digit operator*(const int, const Digit&);

	Digit operator/(const Digit&) const;
	Digit operator/(const int) const;
	friend Digit operator/(const int, const Digit&);

	Digit operator%(const Digit&) const;
	Digit operator%(const int) const;
	friend Digit operator%(const int, const Digit&);

	bool operator>(const Digit&) const;
	bool operator>(const int) const;

	bool operator<(const Digit&) const;
	bool operator<(const int) const;

	bool operator==(const Digit&) const;
	bool operator==(const int) const;

	bool operator!=(const Digit&) const;
	bool operator!=(const int) const;

	bool operator>=(const Digit&) const;
	bool operator>=(const int) const;

	bool operator<=(const Digit&) const;
	bool operator<=(const int) const;

	Digit& operator++();
	Digit operator++(int);

	Digit& operator--();
	Digit operator--(int);

	Digit& operator=(const Digit&);
	Digit& operator=(Digit&&);
};
