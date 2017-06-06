#include"PrettyPrint.h"

std::string PrettyPrint::concatenation(std::string a, std::string b) const {
	std::string str = a + '.' + b;
	return str;
}

std::string PrettyPrint::substitution(std::string c) {
	for (std::string::iterator it = c.begin(); it != c.end(); ++it)

	if (*it == 'a')*it = 'o';
	return c;
}

void PrettyPrint::coup(std::string *d) {
	int a1 = (*d).size();
	std::string temp = (*d);
	for (int a2 = 0; a2 < (*d).size() / 2; a2++, a1--)
	{
		(*d).at(a2) = (*d).at(a1 - 1);
		(*d).at(a1 - 1) = (temp).at(a2);
	}
}
