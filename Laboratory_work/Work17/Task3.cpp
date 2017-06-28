#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<ctime>
#include<iterator>

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

class Pred {
	bool flag;
	int counter = { 0 };
public:
	Pred(const bool x) : flag(x){};
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

	std::replace_if(vec.begin(), vec.end(), Pred(true), 8);
	print(vec);

	std::vector<int> copy_vec(vec.size());
	std::copy(vec.begin(), vec.end(), copy_vec.begin());
	print(copy_vec);

	std::replace_if(copy_vec.begin(), copy_vec.end(), Pred(false), 3);
	print(copy_vec);

	std::vector<int> last_vec;
	std::back_insert_iterator<std::vector<int>>back_it(last_vec);
	std::copy_if(copy_vec.begin(), copy_vec.end(), back_it, std::bind(std::less<int>(), std::placeholders::_1, 5));
	print(last_vec);

	std::transform(last_vec.begin(), last_vec.end(), last_vec.begin(), Pred1());
	print(last_vec);

	std::reverse(last_vec.begin(), last_vec.end());
	print(last_vec);

	std::iter_swap(last_vec.begin(), --(--last_vec.end()));
	print(last_vec);

	std::iter_swap(++last_vec.begin(), last_vec.end() - 3);
	print(last_vec);

	std::rotate(last_vec.begin(), last_vec.begin() + last_vec.size()/2, last_vec.end());
	print(last_vec);

	return 0;
}
