#pragma once
#include<cmath>
#include<iostream>
#include<string>

class Square
{
	int sideA, sideB;
public:
	Square() = default;

	void setsideA(const int);
	void setsideB(const int);
	
	int getSquareArea(int) const;
	int getSquareArea(int, int) const;

	void Square::menu();
};
