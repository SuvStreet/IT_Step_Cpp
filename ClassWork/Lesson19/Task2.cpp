#include<iostream>
#include<list>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::list<std::size_t> lis;
	for (size_t i = 13; i < 13 * 21; i += 13) {
		lis.push_back(i);
	}
	// 1) Создали контейнер типа std::list и заполнили его 20 числами, кратными 13.

	std::cout << lis.size() << std::endl;
	for (auto& number : lis) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
	// 2) Вывелили в консоль размер списка и все его элементы через пробел

	size_t sum = 0, x;
	for (auto it = lis.begin(); it != lis.end(); ++it) {
		sum += (*it);
	}
	x = sum / lis.size();
	lis.push_front(x);
	// 3) Вставили в начало списка число, равное целой части среднего арифметического всех элементов списка.

	for (auto it = lis.begin(); it != lis.end(); ) {
		if ((*it) == 130) {
			it = lis.erase(it);
			it++;
		}
		else { ++it; }
	}
	for (auto& number : lis) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
	// 4) Удалили из списка число 130

	size_t index = 1;
	for (auto it = lis.begin(); it != lis.end(); ++it, ++index) {
		if (index == 10) {
			(*it *= 3);
		}
	}
	for (auto& number : lis) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
	// 5) Увеличили 10-е число в 3 раза

	lis.pop_back();
	for (auto& number : lis) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
	// 6) Удалили из списка последнее число 

	size_t second = lis.back();
	auto it = --(--(--(lis.end())));
	sum = second + (*it);
	(*++it) = sum;
	for (auto it = lis.begin(); it != lis.end(); ++it) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
	// 7)

	size_t counter = 1;
	for (auto it = lis.begin(); it != lis.end(); ++counter) {
		if (counter % 3 == 0) it = lis.erase(it++);
		else { ++it; }
	}
	for (auto& number : lis) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
	// 8)

	lis.push_back(70);
	for (auto& number : lis) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
	// 9) Вставили в конец списка число 70

	size_t s = 0;
	for (auto it = lis.begin(); it != lis.end(); ++it) {
		s += (*it);
	}
	std::cout << s << std::endl;

	std::cout << std::endl;
	return 0;
}
