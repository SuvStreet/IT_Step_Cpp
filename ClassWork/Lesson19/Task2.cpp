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
	lis.pop_front();
	std::cout << x << std::endl;


	std::cout << std::endl;
	return 0;
}
