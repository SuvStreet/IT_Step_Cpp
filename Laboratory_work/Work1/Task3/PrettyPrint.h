#pragma once
#include<iostream>
#include<string>

class PrettyPrint
{
public:
	PrettyPrint() {};
	std::string concatenation(std::string, std::string) const;
	std::string substitution(std::string);
	void coup(std::string*);
};
