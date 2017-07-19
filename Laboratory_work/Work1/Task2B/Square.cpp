#include"Square.h"
#include<cmath>

void Square::setsideA(const double a)
{
	side = a;
}

void Square::setsideB(const double b)
{
	side = b;
}

double Square::squareArea(double a) const
{
	return pow(a, 2);
}

double Square::squareArea(double a, double b) const
{
	return a * b;
}
