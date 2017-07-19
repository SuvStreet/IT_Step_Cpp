#pragma once
#include <string>

class PrettyPrint
{
public:
	static std::string concatenate(std::string&, std::string&);
	static std::string replace(std::string&);
	static std::string coup(std::string&);
	~PrettyPrint() {}
};
