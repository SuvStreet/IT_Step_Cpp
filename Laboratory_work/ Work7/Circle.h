#pragma once

#define PI 3.1415926535897932384626433832795
#include<cmath>
#include<iostream>
#include<string>
#include<cmath>

class Circle
{
	double radius;
	int x, y;
public:
	Circle() = delete;
	Circle(const int, const int, const double);
	Circle(const Circle&);
	Circle(Circle&&);

	Circle& operator=(Circle&&);

	bool operator==(const Circle);
	bool operator!=(const Circle);

	bool operator>(const Circle);
	bool operator<(const Circle);

	Circle operator+(int);
	Circle operator-(int);

	Circle& operator++();
	Circle& operator--();

	Circle operator++(int);
	Circle operator--(int);

	void operator()(int, int, double);

	int getX() const;
	int getY() const;
	double getRadius() const;

	double getAreaCircle() const;
	double getLengthCircle() const;
	
	void setX(const int);
	void setY(const int);
	void setRadius(const int);

	~Circle() = default;
};
