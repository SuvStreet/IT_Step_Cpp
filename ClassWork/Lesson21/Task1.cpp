#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>

void fuc1() {
	std::vector<int> vec = { 10, -5, 15, 0, -1, -5, 1, 5, 19, 2, -4, -5, -1, 0, -1, 16, 7, -1, -5, 0 };
	for (auto& number : vec) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
	// 1. Создайте вектор чисел из 20 элементов со значениями от - 10 до 10 и напечатайте его.

	size_t quantity = std::count(vec.begin(), vec.end(), 0);
	std::cout << quantity;
	std::cout << std::endl;
	// 2. Сосчитайте, сколько раз в вашем списке содержится число 0.
	std::replace(vec.begin(), vec.end(), -1, 1);
	for (auto& number : vec) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
	// 3. Замените все вхождения числа - 1 на 1

	auto it = std::find(vec.begin(), vec.end(), 5);
	*(++it) = 6;
	for (auto& number : vec) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
	// 4. Измените список так, чтобы после числа 5 шло число 6

	auto it1 = std::remove(vec.begin(), vec.end(), -5);
	vec.erase(it1, vec.end());
	// 5. Удалите все вхождения числа - 5.	for (auto& number : vec) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
	// 6. Выведите получившийся список в консоль
}

struct DeleteR {
	bool operator()(const std::string& str) {
		return str[0] == 'r';
	}
};

bool deleteC(const std::string& str) {
		return str[0] == 'c';
	}

class DeleteSymbol {
	char symbol;
public:
	DeleteSymbol(char a) : symbol(a) {};
	bool operator()(const std::string& a1) const {
		return a1[0] == 'f';
	}
};

class Predator {
	int value;
public:
	Predator(const int v) : value(v) {}
		bool operator()(const int element) {
			return element < value || (!(element % 2));
		}
};

template<typename T>
void print(T& value) {
	for (auto temp : value) {
		std::cout << temp << " ";
	}
}

int main()
{
	/*std::list<std::string> lis = {"rbc", "ce", "rif", "w", "rc", "cec", "far", "good", "hello", "fick", "pip"};
	lis.remove_if(DeleteR());
	lis.remove_if(deleteC);
	lis.remove_if(DeleteSymbol('f'));

	for (auto& symbol : lis) {
		std::cout << symbol << "  ";
	}
	std::cout << std::endl;*/

	std::list<int> newLis = { 10, -5, 15, 0, -1, -5, 1, 5, 19, 2, -4, -5, -1, 0, -1, 16, 7, -1, -5, 0 };

	size_t res = std::count_if(newLis.begin(), newLis.end(), Predator(0));
	std::cout << res << std::endl;

	std::replace_if(newLis.begin(), newLis.end(), Predator(0), 0);
	print(newLis);
	std::cout << std::endl;

	auto it = std::find_if(newLis.begin(), newLis.end(), Predator(2));
	print(newLis);
	std::cout << std::endl;

	auto it1 = std::remove(newLis.begin(), newLis.end(), 1);
	newLis.erase(it1, newLis.end());

	print(newLis);
	std::cout << std::endl;

	return 0;
}
