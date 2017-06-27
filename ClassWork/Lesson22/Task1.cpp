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
		value.push_back(rand() % x - x - 1);
	}
	print(value);
}

int main()
{
	std::vector<int> vec = { 1, 1, -5, 15, -1, -5, 1, 10, 19, 2, -4, -5, -1, 0, -1, 16, 10, -1, -5, 0 };
	//random(vec, 20);
	print(vec);

	size_t counter = std::count(vec.begin(), vec.end(), 10);
	std::cout << counter << std::endl;

	counter = std::count_if(vec.begin(), vec.end(), std::bind(std::less_equal<int>(), std::placeholders::_1, 10));
	std::cout << counter << std::endl;

	auto it = std::find_if(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 10));
	std::cout << *(it) << std::endl;
	
	it = std::find_if_not(vec.begin(), vec.end(), std::bind(std::equal_to<int>(), std::placeholders::_1, 1));
	std::cout << *(it) << std::endl;

	it = std::adjacent_find(vec.begin(), vec.end());
	std::cout << *(it) << std::endl;

	bool q = std::all_of(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 0));
	std::cout << std::boolalpha << q << std::endl;

	q = std::all_of(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1, 5));
	std::cout << std::boolalpha << q << std::endl;

	q = std::any_of(vec.begin(), vec.end(), std::bind(std::less<int>(), std::placeholders::_1, 0));
	std::cout << std::boolalpha << q << std::endl;

	return 0;
}
