#pragma once

#define PI 3.1415926535897932384626433832795
#include<iostream>
#include<cmath>

class Area
{
	static int counter;
	int sideA, sideB, height, diagonalA, diagonalB;
	double angle;
public:
	Area() = default;

	void setsideA(const int);
	void setsideB(const int);
	void setheight(const int);
	void setdiagonalA(const int);
	void setdiagonalB(const int);
	void setangle(const double);

	static int getRectangleArea(int, int);
	static int getRectangleArea(int);

	static int getParallelogramArea(int, int);
	static double getParallelogramArea(int, int, double);

	static double getRhombusArea(int, double);
	static double getRhombusArea(int, int);

	static int getCounter() { return counter; }

	void menu();

	~Area() = default;
};
