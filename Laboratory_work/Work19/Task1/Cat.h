#pragma once
#include "Pet.h"

class Cat :
	public Pet
{
public:
	Cat(const std::string a, std::string n = 0) : Pet(a, n) {};
	void sound() { std::cout << "May-May" << std::endl; }
	~Cat() = default;
};
