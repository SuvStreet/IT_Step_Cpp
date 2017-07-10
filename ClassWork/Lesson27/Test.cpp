#include<iostream>

namespace number {
	const size_t a = 42;
}

namespace number {
	const size_t b = 150;
	const size_t c = 500;
}

const size_t x = 100;

namespace {
	void f() { std::cout << "Test 1" << std::endl; }
}

namespace z {
	void foo() {
		std::cout << "a{} void f();" << std::endl;
	}
	namespace {
		size_t ai = 555;
		void f2() { foo();
			std::cout << "{} void p();" << std::endl;
		}

	}
	void pi() { std::cout << z::ai << std::endl; }
}


int main() {
	setlocale(LC_ALL, "Russian");
	
	z::f2();
	z::pi();
	z::ai;
	

	std::cout << std::endl;

	using namespace number;

	std::cout << "Namespace1 = " << a << std::endl;
	
	std::cout << "Namespace2 = " << b << std::endl;

	const size_t x = 112;
	std::cout << "Main x = " << x << std::endl;

	std::cout << "Глобальное x = " << ::x << std::endl;

	::f();

	namespace n = number;
	std::cout << "Псевдоним n = " << n::c << std::endl;

	return 0;
}
