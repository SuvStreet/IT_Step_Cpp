#include<iostream>
#include "Windows.h"

template<typename T, typename U>
auto getMin(const T t, const U u) -> decltype(t + u) {
	return (t < u ? t : u);
}

int main() {
	setlocale(LC_ALL, "Russian");
	double t, u;
	std::cout << "Введите первое число: ";
	std::cin >> t;
	std::cout << "Введите второе число: ";
	std::cin >> u;
	std::cout << "Наименьший элемент: " << getMin(t, u) << "\n" << std::endl;
	return 0;
}
