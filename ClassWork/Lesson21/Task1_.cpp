#include<iostream>
#include<algorithm>
#include<vector>

template<typename T>
void print(T& value){
	for (auto temp : value){
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<int> vec = { 10, -5, 15, 0, -1, -5, 1, 5, 19, 2, -4, -5, -1, 0, -1, 16, 7, -1, -5, 0 };
	std::cout << "Task_1:	";
	print(vec);
	// 1) Создаём вектор чисел из 20 элементов со значениями от - 10 до 10 и печатаем его.

	size_t quantity = std::count(vec.begin(), vec.end(), 0);
	std::cout << "Task_2:	" << quantity << std::endl;
	// 2) Считаем, сколько раз в нашем списке содержится число 0.

	std::replace(vec.begin(), vec.end(), -1, 1);
	std::cout << "Task_3:	";
	print(vec);
	// 3) Заменяем все вхождения числа - 1 на 1.

	auto it = std::find(vec.begin(), vec.end(), 5);
	*(++it) = 6;
	std::cout << "Task_4:	";
	print(vec);
	// 4) Изменяем список так, чтобы после числа 5 шло число 6.

	auto it1 = std::remove(vec.begin(), vec.end(), -5);
	vec.erase(it1, vec.end());
	std::cout << "Task_5:	";
	print(vec);
	// 5) Удаляем все вхождения числа - 5.

	std::cout << "Task_6:	";
	print(vec);
	// 6) Выводим получившийся список в консоль.

	return 0;
}
