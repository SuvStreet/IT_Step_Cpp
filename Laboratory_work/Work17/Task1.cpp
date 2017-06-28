#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

template<typename T>
void print(T& value) {
	for (auto temp : value) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec = { 1, 1, -5, 15, -1, -5, 1, 10, 19, 2, -4, -5, -1, 0, -1, 16, 10, -1, -5, 0 };
	std::cout << "Task_1:	";
	print(vec);
	// 1) Создаём вектор из 20 целых чисел.

	size_t counter = std::count(vec.begin(), vec.end(), 10);
	std::cout << "Task_2:	";
	std::cout << counter << std::endl;
	// 2) Считаем, сколько раз в векторе встречается число 10.

	counter = std::count_if(vec.begin(), vec.end(), std::bind(std::less_equal<int>(), std::placeholders::_1, 10));
	std::cout << "Task_3:	";
	std::cout << counter << std::endl;
	// 3) Считаем, сколько в векторе чисел, не превышающих 10.

	auto it = std::find_if(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 10));
	std::cout << "Task_4:	";
	std::cout << *(it) << std::endl;
	// 4) Находим первое число, которое больше, чем 10.

	it = std::find_if_not(vec.begin(), vec.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, 1));
	std::cout << "Task_5:	";
	std::cout << *(it) << std::endl;
	// 5) Находим первое число, которое не равно 1.

	it = std::adjacent_find(vec.begin(), vec.end());
	std::cout << "Task_6:	";
	std::cout << *(it) << std::endl;
	// 6) Проверяем, есть ли в векторе соседние элементы с одинаковым значением.

	bool q = std::all_of(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 0));
	std::cout << "Task_7:	";
	std::cout << std::boolalpha << q << std::endl;
	// 7) Устанавливаем, верно ли, что в векторе все элементы больше 0.

	q = std::all_of(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 5));
	std::cout << "Task_8:	";
	std::cout << std::boolalpha << q << std::endl;
	// 8) Устанавливаем, верно ли, что в векторе все элементы больше 5.

	q = std::any_of(vec.begin(), vec.end(), std::bind(std::less<int>(), std::placeholders::_1, 0));
	std::cout << "Task_9:	";
	std::cout << std::boolalpha << q << std::endl;
	// 9) Устанавливаем, верно ли, что в первом векторе есть хотя бы одно отрицательное значение.

	return 0;
}
