#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<iterator>

template<typename T>
void print(T& value) {
	for (auto temp : value) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}

class Pred {
	bool flag;
	int counter = { 0 };
public:
	Pred(const bool x) : flag(x) {};
	bool operator()(int value) {
		if ((++counter % 2 == 0) == flag) return true;
		else return false;
	}
};

class Pred1 {
	int index = 0;
public:
	int operator()(const int value) {
		return index++;
	}
};

int main()
{
	std::vector<int> vec(20, 5);
	std::cout << "Task_1:	";
	print(vec);
	// 1) Создаём вектор и заполняем его 20 элементами, значение которых будет равно 5.

	std::replace_if(vec.begin(), vec.end(), Pred(true), 8);
	std::cout << "Task_2:	";
	print(vec);
	// 2) Заменяем каждый второй элемент на 8.

	std::vector<int> copy_vec(vec.size());
	std::copy(vec.begin(), vec.end(), copy_vec.begin());
	std::cout << "Task_3:	";
	print(copy_vec);
	// 3) Копируем исходный вектор в новый вектор под названием copy_vec.

	std::replace_if(copy_vec.begin(), copy_vec.end(), Pred(false), 3);
	std::cout << "Task_4:	";
	print(copy_vec);
	// 4) Заменяем в векторе copy_vec каждый первый элемент на 3.

	std::vector<int> last_vec;
	std::back_insert_iterator<std::vector<int>>back_it(last_vec);
	std::copy_if(copy_vec.begin(), copy_vec.end(), back_it, std::bind(std::less<int>(), std::placeholders::_1, 5));
	std::cout << "Task_5:	";
	print(last_vec);
	// 5) Копируем из copy_vec все значения, меньшие 5, в новый вектор под названием last_vec.

	std::transform(last_vec.begin(), last_vec.end(), last_vec.begin(), Pred1());
	std::cout << "Task_6:	";
	print(last_vec);
	// 6) Заменяем в векторе last_vec значение всех элементов на индексы этих элементов.

	std::reverse(last_vec.begin(), last_vec.end());
	std::cout << "Task_7:	";
	print(last_vec);
	// 7) Изменяем в векторе last_vec порядок элементов на обратный.

	std::iter_swap(last_vec.begin(), --(--last_vec.end()));
	std::cout << "Task_8:	";
	print(last_vec);
	// 8) В векторе last_vec обмениваем значения первого и предпоследнего элементов.

	std::iter_swap(++last_vec.begin(), last_vec.end() - 3);
	std::cout << "Task_9:	";
	print(last_vec);
	// 9) В векторе last_vec обменитваем местами значение второго элемента от начала и третьего с конца.

	std::rotate(last_vec.begin(), last_vec.begin() + last_vec.size() / 2, last_vec.end());
	std::cout << "Task_10:";
	print(last_vec);
	// 10) Циклически сдвигаем элементы вектора last_vec на половину его длины.

	return 0;
}
