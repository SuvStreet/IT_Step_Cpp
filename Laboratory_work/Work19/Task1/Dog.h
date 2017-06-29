#pragma once
#include "Pet.h"

class Dog :
	public Pet
{
public:
	Dog(const std::string a, std::string n = 0) : Pet(a, n) {}
	void sound() { std::cout << "Gav-Gav" << std::endl; }
	~Dog() = default;
};
