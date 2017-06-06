#pragma once
#define PI 3.1415926535897932384626433832795
#include<cmath>
#include<iostream>
#include<string>

class Triangle
{
	int sideA, sideB, sideC, base, height;
	float angle;
public:
	Triangle() {};

	void setsideA(const int);
	void setsideB(const int);
	void setsideC(const int);
	void setbase(const int);
	void setheight(const int);
	void setangle(const float);

	int getTriangleArea(int, int) const;
	double getTriangleArea(int, int, float) const;
	double getTriangleArea(double, double, double) const;

	void Triangle::menu();
};
