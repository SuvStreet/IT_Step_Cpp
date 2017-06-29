#pragma once
#include "Parrot.h"

class Bird :
	public Parrot
{
public:
	Bird(const std::string a, std::string n = 0) : Parrot(a, n) {}
	void sound() { std::cout << "Chik-chirik" << std::endl; }
	~Bird() = default;
};
