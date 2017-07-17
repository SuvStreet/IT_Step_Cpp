#pragma once
#include "Shape.h"

class Circle : public Shape
{
	double radius = 0;
	double centerX = 0;
	double centerY = 0;
public:
	Circle(const double, const double, const double);

	double getSideA() const;
	void setSideA(const double);

	double getCenterX() const;
	void setCenterX(const double);

	double getCenterY() const;
	void setCenterY(const double);

	double getArea();

	~Circle() {}
};
