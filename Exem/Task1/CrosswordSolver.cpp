#include "CrosswordSolver.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

CrosswordSolver::CrosswordSolver(const std::string x) { // конструктор с параметрами, если пользователь указал пустую строку открывается "Lopatin_dictionary.txt"
	if (x == "") {
		readFile("Lopatin_dictionary.txt");
	}
	else readFile(x);
}

void CrosswordSolver::readFile(std::string name) { // открытие файла заданного пользователем
	std::ifstream filein;
	filein.open(name);
	if (!filein.is_open()) { std::cout << "File not found!" << std::endl; }

	std::string temp;
	while (filein >> temp) {
		myVecString.push_back(temp);
		}
	filein.close();
}

void CrosswordSolver::addBase(std::string word) { // добовление слова в базу слов

	if (word == "") { std::cout << "Base word remains the same." << std::endl; }
	else {
		std::ifstream filein;
		filein.open("Lopatin_dictionary.txt");
		if (!filein.is_open()) { std::cout << "File not found!" << std::endl; }

		std::string tmp;
		std::vector<std::string> temp;
		while (filein >> tmp) {
			temp.push_back(tmp);
		}

		filein.close();

		for (auto it = temp.begin(); it != temp.end(); ++it) {
			if (word == *it) {
				std::cout << "Such a word is already.\nBase word remains the same." << std::endl;
				break;
			}
			if (it == --temp.end()) {
				temp.push_back(word);

				std::sort(temp.begin(), temp.end());

				std::ofstream fileout;
				fileout.open("Lopatin_dictionary.txt");
				if (!fileout.is_open()) { std::cout << "The file is not created!" << std::endl; }

				for (auto& x : temp) {
					fileout << x << '\n';
				}

				fileout.close();
				std::cout << "New base word!" << std::endl;
				break;
			}
		}
	}
}

void CrosswordSolver::getAllWithLen(size_t value, std::string name) { // поиск по длине слова в файле указанным пользователем

	std::ofstream fileout;
	fileout.open(name);
	if (!fileout.is_open()) { std::cout << "The file is not created!" << std::endl; }

	for (auto& x : myVecString) {
		if (x.size() == value) {
			fileout << x << "\n";
		}
	}
	fileout.close();
}

void CrosswordSolver::getAllWithInit(char value, std::string name) { // поиск слов по первой букве в файле указанным пользователем

	std::ofstream fileout;
	fileout.open(name);
	if (!fileout.is_open()) { std::cout << "The file is not created!" << std::endl; }

	for (auto& x : myVecString) {
		if (x[0] == value) {
			fileout << x << "\n";
		}
	}

	fileout.close();
}

void CrosswordSolver::getAnagrams(std::string value, std::string name) { // поиск анаграмм в файле указанным пользователем

	std::ofstream fileout;
	fileout.open(name);
	if (!fileout.is_open()) { std::cout << "The file is not created!" << std::endl; }

	std::sort(value.begin(), value.end());
	for (auto& x : myVecString)
	{
		std::string temp = x;
		std::sort(temp.begin(), temp.end());
		if (value == temp)
		{
			fileout << x << '\n';
		}
	}

	fileout.close();
}
