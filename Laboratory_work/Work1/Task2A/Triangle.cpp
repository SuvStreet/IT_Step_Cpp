#define PI 3.1415926535897932384626433832795
#include"Triangle.h"
#include<cmath>
#include<iostream>

void Triangle::setsideA(const int a)
{
	sideA = a;
}

void Triangle::setsideB(const int b)
{
	sideA = b;
}

void Triangle::setsideC(const int c)
{
	sideA = c;
}

void Triangle::setbase(const int newbase)
{
	base = newbase;
}
void Triangle::setheight(const int newheight)
{
	height = newheight;
}
void Triangle::setangle(const float newangle)
{
	angle = newangle;
}

int Triangle::getTriangleArea(int base, int height) const
{
	return 0.5 * base * height;
}

double Triangle::getTriangleArea(int sideA, int sideB, float angle) const
{
	return sin(angle * PI / 180) * 0.5 * sideA * sideB;
}

double Triangle::getTriangleArea(double sideA, double sideB, double sideC) const
{
	double p = (sideA + sideB + sideC) / 2;
	double S = sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
	return S;
}
