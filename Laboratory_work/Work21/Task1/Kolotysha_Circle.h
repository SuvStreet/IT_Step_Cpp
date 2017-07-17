#pragma once
#include "Shape.h"

class Circle : public Shape
{
	double radius = 0;
	double centerX_Y = 0;
public:
	Circle(const double, const double);

	double getSideA() const;
	void setSideA(const double);

	double getCenterX_Y() const;
	void setCenterX_Y(const double);

	double getArea();

	~Circle() {}
};
