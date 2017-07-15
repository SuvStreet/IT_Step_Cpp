#pragma once
#include "Shape.h"

class Parallelogram : public Shape
{
	double sideA = 0;
	double sideB = 0;
	double angleA = 0;
public:
	Parallelogram() {}
	Parallelogram(const double, const double, const double);

	double getSideA() const;
	void setSideA(const double);

	double getSideB() const;
	void setSideB(const double);

	double getAngleA() const;
	void setAngleA(const double);

	double getArea();

	virtual ~Parallelogram() {}
};
