#pragma once
#include <vector>

class CrosswordSolver
{
	std::vector<std::string> myVecString;
public:
	CrosswordSolver(std::string);

	void readFile(std::string);
	void addBase(std::string);

	void getAllWithLen(size_t, std::string);
	void getAllWithInit(char, std::string);
	void getAnagrams(std::string, std::string);

	~CrosswordSolver(){}
};
