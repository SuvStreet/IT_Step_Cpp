#include<iostream>
#include<algorithm>
#include<list>
#include<string>

template<typename T>
void print(T& value){
	for (auto temp : value){
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}

struct DeleteR {
	bool operator()(const std::string& str) {
		return str[0] == 'r';
	}
};

bool deleteC(const std::string& str) {
	return str[0] == 'c';
}

class DeleteSymbol {
	char symbol;
public:
	DeleteSymbol(char a) : symbol(a) {};
	bool operator()(const std::string& a1) const {
		return a1[0] == 'f';
	}
};

int main()
{
	std::list<std::string> lis = {"rbc", "ce", "rif", "w", "rc", "cec", "far", "good", "hello", "fick", "pip"};
	std::cout << "List:			";
	print(lis);

	std::cout << "Delete 'r':		";
	lis.remove_if(DeleteR());
	print(lis);

	std::cout << "Delete 'c':		";
	lis.remove_if(deleteC);
	print(lis);

	std::cout << "Delete simbol 'f':	";
	lis.remove_if(DeleteSymbol('f'));
	print(lis);

	std::cout << std::endl;
	return 0;
}
