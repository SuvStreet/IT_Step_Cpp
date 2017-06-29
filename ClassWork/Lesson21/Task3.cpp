#include<iostream>
#include<algorithm>
#include<list>

template<typename T>
void print(T& value) {
	for (auto temp : value) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}

class Predator1 {
	int value;
public:
	Predator1(const int v) : value(v) {}
	bool operator()(const int element) {
		return element < value;
	}
};

class Predator2 {
	int value;
public:
	Predator2(const int v) : value(v) {}
	bool operator()(const int element) {
		if (element < value && (!(element % 2 == 0))) return true;
		else return false;
	}
};

class Predator3 {
	int value;
public:
	Predator3(const int v) : value(v) {}
	bool operator()(const int element) {
		return element < value;
	}
};

class Predator4 {
	int value;
public:
	Predator4(const int v) : value(v) {}
	bool operator()(const int element) {
		if (element > value && element % 2 == 0 ) return true;
		else return false;
	}
};

int main()
{
	std::list<int> newLis = { 10, -5, 15, 0, -1, -5, 1, 5, 19, 2, -4, -5, -1, 0, -1, 16, 7, -1, -5, 0 };
	std::cout << "Task_0:	";
	print(newLis);

	size_t res = std::count_if(newLis.begin(), newLis.end(), Predator1(0));
	std::cout << "Task_1:	" << res << std::endl;
	// 1) Считаем, сколько отрицательных чисел содержится в списке из задания 1.
	
	std::replace_if(newLis.begin(), newLis.end(), Predator2(0), 0);
	std::cout << "Task_2:	";
	print(newLis);
	// 2) Заменяем все отрицательные нечетные числа на 0.

	auto it = std::find_if(newLis.begin(), newLis.end(), Predator3(0));
	std::cout << "Task_3:	";
	std::cout << *it << std::endl;
	// 3) Находим значение первого нечетного числа.

	auto it1 = std::remove_if(newLis.begin(), newLis.end(), Predator4(-1));
	newLis.erase(it1, newLis.end());
	// 4) Удаляем все четные числа, которые больше, чем переданное значение.

	std::cout << "Task_5:	";
	print(newLis);
	// 5) Выводим получившийся список в консоль.

	return 0;
}
