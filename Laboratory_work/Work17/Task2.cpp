#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<ctime>

template<typename T>
void print(T& value) {
	for (auto temp : value) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void random(T& value, size_t x) {
	srand(time(0));
	for (size_t i = 0; i < x; ++i) {
		value.push_back(rand() % x * 2 - x);
	}
	print(value);
}

class Sum {
	int sum = { 0 };
public:
	int getSum() const {
		return sum;
	}
	void operator()(const int value) {
		sum += value;
	}
};

int main()
{
	std::vector<int> vec1 = { 1, 1, -5, 15, -1, -5, 1, 10, 19, 2, -4, -5, -1, 0, -1, 16, 10, -1, -5, 0 };
	std::vector<int> vec2;
	std::cout << "Task_1:	";
	print(vec1);
	std::cout << "Task_1:	";
	random(vec2, 20);
	// 1) Создаём два вектора, каждый из которых будет содержать по 20 целых чисел.

	bool q = std::equal(vec1.begin(), vec1.end(), vec2.begin());
	std::cout << "Task_2:	";
	std::cout << std::boolalpha << q << std::endl;
	// 2) Устанавливаем, верно ли, что значение второго вектора совпадает со значением первого.

	q = std::is_permutation(vec1.begin(), vec1.end(), vec2.begin());
	std::cout << "Task_3:	";
	std::cout << std::boolalpha << q << std::endl;
	// 3) Устанавливаем, верно ли, что второй вектор состоит из тех же элементов, что и первый, хотя значения могут идти в другом порядке.

	auto it = std::mismatch(vec1.begin(), vec1.end(), vec2.begin());
	std::cout << "Task_4:	";
	std::cout << *(it.first) << "	" << *(it.second) << std::endl;
	// 4) Найходим первую по счету пару значений, которыми различаются первый и второй векторы (если таковые существуют).

	std::vector<int> vec3 = { 1, 2 };
	auto it1 = std::search(vec2.begin(), vec2.end(), vec3.begin(), vec3.end());
	if (it1 != vec2.end()) std::cout << "Task_5:	" << *(it1) << std::endl;
	else std::cout << "Task_5:	iterator == vec2.end()" << std::endl;
	// 5) Проверяем, входит ли во второй вектор подпоследовательность {1, 2}.

	std::vector<int> vec4 = { 1, 1, 1 };
	auto it2 = std::search(vec1.begin(), vec1.end(), vec4.begin(), vec4.end());
	if (it2 != vec1.end()) std::cout << "Task_6:	" <<  *(it1) << std::endl;
	else std::cout << "Task_6:	iterator == vec1.end()" << std::endl;
	// 6) Проверяем, входит ли в первый вектор подпоследовательность {1, 1, 1}.

	Sum s1 = std::for_each(vec1.begin(), vec1.end(), Sum());
	Sum s2 = std::for_each(vec2.begin(), vec2.end(), Sum());
	std::cout << "Task_7.1:	";
	std::cout << s1.getSum() << std::endl;
	// 7.1) сумма первого вектора
	std::cout << "Task_7.2:	";
	std::cout << s2.getSum() << std::endl;
	// 7.2) сумма второго вектора
	int x = s1.getSum() + s2.getSum();
	std::cout << "Task_7:		";
	std::cout << x << std::endl;
	// 7) Найдите сумму всех элементов первого и второго векторов.

	return 0;
}
