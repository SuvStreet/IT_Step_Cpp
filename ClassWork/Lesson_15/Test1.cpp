#include<iostream>

template<typename T>
auto sum(const T value) {
	return value;
}

template<typename T, typename ... Args>
auto sum(const T head, const Args ... values)
{
	return(head + sum(values...));
}

int main()
{
	std::cout << sum(10, 2.5, 8.4, 4.6) << "\n";
	return 0;
}
