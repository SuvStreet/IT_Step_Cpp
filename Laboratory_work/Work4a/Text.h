#pragma once

#include<iostream>
#include<string>
#include<fstream>

class Text
{
	std::string* str;
	size_t size;
	int MAX_len = 0;
	std::string MAX_word;
	void recovery(int word, std::string name);
public:
	Text();
	Text(int);
	Text(std::string name);
	Text(std::string name, int);
	Text(const Text&);
	Text(Text&&);

	~Text() { delete[] str; };

	size_t get_max_len() const;
	std::string get_max_word() const;

};
