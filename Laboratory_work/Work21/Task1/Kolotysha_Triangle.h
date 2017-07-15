#pragma once
#include "Shape.h"

class Triangle : public Shape
{
	double sideA = 0;
	double sideB = 0; 
	double sideC = 0;
	double angleA = 0;
	double angleB = 0;
	double angleC = 0;
public:
	Triangle(const double, const double, const double, const size_t);
	bool test(double, double, double);

	double getSideA()const;
	void setSideA(const double);
	
	double getSideB() const;
	void setSideB(const double);

	double getSideC() const;
	void setSideC(const double);

	double getAngleA() const;
	void setAngleA(const double);

	double getAngleB() const;
	void setAngleB(const double);

	double getAngleC() const;
	void setAngleC(const double);

	double getArea();

	~Triangle() {}
};
