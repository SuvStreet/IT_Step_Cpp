#pragma once
#include "Pet.h"

class Parrot :
	public Pet
{
public:
	Parrot(const std::string a, std::string n = 0) : Pet(a, n) {}
	void sound() { std::cout << "Chik-chirik" << std::endl; }
	~Parrot() = default;
};
