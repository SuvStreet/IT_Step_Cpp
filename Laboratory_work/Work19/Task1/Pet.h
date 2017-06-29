#pragma once
#include<iostream>
#include<string>

class Pet
{
	std::string animal;
	std::string name;
public:
	Pet(const std::string a, std::string n = 0) : animal(a), name(n) {}
	virtual void sound() = 0;
	void setName(const std::string);
	
	std::string show() const;
	std::string type() const;

	virtual ~Pet() {}
};
