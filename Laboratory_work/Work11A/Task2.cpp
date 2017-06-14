#include<iostream>
#include<cstring>

template<typename T>
auto myPrintf(const T value) {
	std::cout << value << std::endl;
}

template<typename T, typename ... Args>
void myPrintf(const char* str, T head, const Args ... tail)
{
	for (size_t i = 0; i < strlen(str); ++i) {
		if (str[i] == '%') {
			std::cout << head;
			myPrintf(str + i + 1, tail ...);
			break;
		}
		else std::cout << str[i];
	}
}

int main()
{
	myPrintf(" Hello, %!", "world");
	myPrintf(" Tel: % - % - %", 279, 13, 54);
	myPrintf(" User: %\n Surname: %\n Age: %\n Score: %\n", "MyName", "MySurname", 25, 15.119);
	return 0;
}
