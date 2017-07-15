#pragma once
#include "Kolotysha_Rectangle.h"

class Square : public Rectangle
{
public:
	Square(const double a);
	
	double getSideA() const;
	void setSideA(const double);

	double getArea();

	~Square() {}
};
