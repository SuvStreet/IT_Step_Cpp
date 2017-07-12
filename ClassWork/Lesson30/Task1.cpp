#include <iostream>
#include <ctime>

int main() {
	try {
		std::srand(std::time(NULL));
		int value = std::rand() % 150;
		std::cout << value << std::endl;
		if (value >= 0 && value <= 10) {
			throw 1;
		}
		else if(value >= 11 && value <= 100) {
			throw 'z';
		}
		else {
			throw 1.0;
		}
		std::cout << "END TRY" << std::endl;
	}
	catch (int x) {
		std::cout << "Exception 0 < x < 10" << std::endl; 
	}
	catch (char c) {
		std::cout << "Exception 11 < x < 100" << std::endl;
	}
	catch (double a) {
		std::cout << "Exception x > 100" << std::endl;
	}

	return 0;
}
