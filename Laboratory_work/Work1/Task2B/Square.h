#pragma once

class Square
{
	double side = 0;
public:
	Square() = default;

	void setsideA(const double);
	void setsideB(const double);

	double squareArea(double) const;
	double squareArea(double, double) const;
	
	~Square() = default;
};
