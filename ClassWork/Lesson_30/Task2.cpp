#include <iostream>
#include <ctime>

void f4();
void f3();
void f2();
void f1();

int main() {
	try {
		f1();
		std::cout << "END TRY" << std::endl;
	}
	catch (const char * x) {
		std::cout << x << std::endl; 
	}

	return 0;
}

void f1() {
	std::cout << "Start f1()" << std::endl;
	f2();
	std::cout << "End f1()" << std::endl;
}

void f2() {
	std::cout << "Start f2()" << std::endl;
	f3();
	std::cout << "End f2()" << std::endl;
}

void f3() {
	std::cout << "Start f3()" << std::endl;
	f4();
	std::cout << "End f3()" << std::endl;
}

void f4() {
	std::srand(std::time(NULL));
	int value = std::rand() % 30;
	std::cout << "Value = " << value << std::endl;
	if (value % 3 == 0 || value % 5 == 0) {
		throw "fizz";
	}
	else if (value % 15 == 0) {
		throw "buzz";
	}
}
