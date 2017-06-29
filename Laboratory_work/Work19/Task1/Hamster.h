#pragma once
#include "Pet.h"

class Hamster :
	public Pet
{
	
public:
	Hamster(const std::string a, std::string n = 0) : Pet(a, n) {}
	void sound() { std::cout << "Om-Nom-Nom" << std::endl; }
	~Hamster() = default;
};
