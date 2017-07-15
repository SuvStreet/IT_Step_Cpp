#pragma once
#include "Shape.h"

class Circle : public Shape
{
	double radius = 0;
public:
	Circle(const double);

	double getSideA() const;
	void setSideA(const double);

	double getArea();

	~Circle() {}
};
