#pragma once
#include "Kolotysha_Parallelogram.h"

class Rectangle : public Parallelogram
{
public:
	Rectangle() {}
	Rectangle(const double, const double);

	double getSideA() const;
	void setSideA(const double);

	double getSideB() const;
	void setSideB(const double);

	double getArea();

	virtual ~Rectangle() {}
};
