#include<iostream>

template<typename T>
auto myPrint(const T value) {
	std::cout << value << std::endl;
}

template<typename T, typename ... Args>
auto myPrint(const T head, const Args ... tail)
{
	std::cout << head << " ";
	myPrint(tail...);
}

void myPrint() {
	std::cout << std::endl;
}

int main()
{
	myPrint();
	myPrint(1);
	myPrint(10, 34, 45.12, 99.1189);
	myPrint(10, 34, 45.12, "text", "new string");
	myPrint("Student", 17, 2017, "18-11S", 9.1);
	return 0;
}
