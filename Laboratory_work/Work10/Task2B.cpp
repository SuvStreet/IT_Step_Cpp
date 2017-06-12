#include<iostream>
#include "Windows.h"

template<char size, typename T>
T getMax(const T* arr) {
	T max =  arr[0];
	for (size_t i = 0; i < size; ++i)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	size_t size;
	std::cout << "Введите размер массива чисел: ";
	std::cin >> size;
	double* arr = new double[size];
	for (size_t i = 0; i < size; ++i){
		std::cout << "Введите [" << i << "] число: ";
		std::cin >> arr[i];
	}

	std::cout << "Наибольший элемент: " << getMax<'size'>(arr) << "\n" << std::endl;
	delete [] arr;
	return 0;
}
