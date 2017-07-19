#include"PrettyPrint.h"

std::string PrettyPrint::concatenate(std::string& a, std::string& b) {
	return a + '.' + b;
}

std::string PrettyPrint::replace(std::string& c) {
	for (std::string::iterator it = c.begin(); it != c.end(); ++it) {
		if (*it == 'a')*it = 'o';
		else if (*it == 'A')*it = 'O';
		else if (*it == 'а')*it = 'о';
		else if(*it == 'А')*it = 'О';
	}
	return c;
}

std::string PrettyPrint::coup(std::string& d) {
	std::string newTemp = "";
	for (int i = d.size() - 1; i >= 0; --i) {
		newTemp += d[i];
	}
	return newTemp;
}
