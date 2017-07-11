#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename T>
void print(T& value) {
	for (auto temp : value) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::vector<size_t> vec = { 1, 10, 3, 4, 10, 6, 7, 8, 9, 10 };
	
	std::replace_if(vec.begin(), vec.end(), [](const size_t x) {return x % 10 == 0; }, 11);
	print(vec);
	// заменить в векторе все числа, кратные 10, на 11;

	std::sort(vec.begin(), vec.end(), [](const size_t a, const size_t b) {return a > b; });
	print(vec);
	// отсортировать данные по убыванию;

	int number = 1;
	int v = 5;
	std::vector<size_t> vec1;
	std::back_insert_iterator<std::vector<size_t>>b_it(vec1);
	std::copy_if(vec.begin(), vec.end(), b_it,
		[number, v](const size_t x)
	{ return (x > number * v) ? true : false; } );
	print(vec1);
	// сохранить в новый вектор только те значения, которые больше переданного значения v в n раз;



	return 0;
}
