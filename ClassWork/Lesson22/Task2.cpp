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
	print(vec1);
	random(vec2, 20);

	bool q = std::equal(vec1.begin(), vec1.end(), vec2.begin());
	std::cout << std::boolalpha << q << std::endl;
	
	q = std::is_permutation(vec1.begin(), vec1.end(), vec2.begin());
	std::cout << std::boolalpha << q << std::endl;

	auto it = std::mismatch(vec1.begin(), vec1.end(), vec2.begin());
	std::cout << *(it.first) << "	" << *(it.second) << std::endl;

	std::vector<int> vec3 = {1, 2};
	auto it1 = std::search(vec2.begin(), vec2.end(), vec3.begin(), vec3.end());
	if (it1 != vec2.end()) std::cout << *(it1) << std::endl;
	else std::cout << "iterator == vec2.end()" << std::endl;

	std::vector<int> vec4 = { 1, 1, 1 };
	auto it2 = std::search(vec1.begin(), vec1.end(), vec4.begin(), vec4.end());
	if (it2 != vec1.end()) std::cout << *(it1) << std::endl;
	else std::cout << "iterator == vec1.end()" << std::endl;

	Sum s1 = std::for_each(vec1.begin(), vec1.end(), Sum());
	Sum s2 = std::for_each(vec2.begin(), vec2.end(), Sum());
	std::cout << s1.getSum() << std::endl;
	std::cout << s2.getSum() << std::endl;
	int x = s1.getSum() + s2.getSum();
	std::cout << x << std::endl;

	return 0;
}
