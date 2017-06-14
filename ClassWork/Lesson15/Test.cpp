#include<iostream>
#include<array>

void print(double* arr, size_t size) {
	for (size_t i = 0; i < size; ++i)
		std::cout << arr[i] << std::endl;
}

int main()
{
	std::array<double, 5>arr = { 1.0, 5.0, 2.0, 3.0, 5.0 };
	print(arr.data(), 5);
	return 0;
}
