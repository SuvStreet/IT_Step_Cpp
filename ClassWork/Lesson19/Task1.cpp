#include<iostream>
#include<vector>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector<int> vec;
	// 1) Создали пустой контейнер типа std::vector

	for (size_t i = 0; i < 100; ++i) {
		if (i % 2 == 0) vec.push_back(i);
	}
	// 2) Заполнили вектор четными числами, лежащими в диапазоне от 1 до 99
	
	std::cout << "Размер вектора: " << vec.size() << std::endl;
	std::cout << "Ёмкость вектора: " << vec.capacity() << std::endl;
	// 3) Вывели в консоль размер и емкость вектора.

	vec[0] = vec.size();
	// 4) Изменили значение первого элемента так, чтобы оно было равно количеству элементов в векторе

	vec.erase(vec.begin() + 7);
	vec.erase(vec.begin() + 14);
	vec.erase(vec.begin() + 21);
	// 5) Удалили из вектора элементы под индексами 7, 14 и 21.

	size_t counter = 0;
	for (size_t i = 0; i < vec.size(); ++i) {
		if (vec[i] % 4 == 0) ++counter;
	}
	std::cout << "Количество чисел кратные 4: " << counter << std::endl;
	// 6) Сосчитали, сколько в векторе элементов, кратных 4, и выведили полученное число в консоль

	vec[21] = 99;
	// 7) Заменили значение 20-го элемента в векторе на 99.

	vec.pop_back();
	// 8) Удалили из вектора последний элемент

	vec.back() = 101;
	// 9) Заменили последний элемент вектора на 101

	std::cout << "Размер вектора: " << vec.size() << std::endl;
	std::cout << "Содержимое вектора: ";
	for (auto& number : vec) {
		std::cout << number << " ";
	}
	// 10) Выведили в консоль размер вектора и все его элементы через пробел

	std::cout << std::endl;
	return 0;
}
