#include<iostream>
#include "Windows.h"

template<typename T>
void sort(T *arr, const size_t size)
{
	for (int d = size / 2; d > 0; d /= 2)
	{
		for (int i = d, j; i < size; i++)
		{
			int temp = arr[i];
			for (j = i; j >= d; j -= d)
			{
				if (temp < arr[j - d])
					arr[j] = arr[j - d];
				else break;
			}
			arr[j] = temp;
		}
	}
}

template<typename T>
T find(T *arr, const size_t size, const T value)
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == value)
		{
			std::cout << "Ваше число находится под индексом [" << i << "]\n" << std::endl;
			return i;
		}
	}
	std::cout << "Число не найдено!!!\n" << std::endl;
	return 0;
}

void print_array(double* arr, int size, char simvol)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << simvol << "[" << i << "] = " << *(arr + i) << "\n";
	}
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
	sort(arr, size);
	std::cout << "\nОтсортированный массив:\n";
	print_array(arr, size, 'A');
	std::cout << std::endl;

	size_t value;
	std::cout << "Введите число которое хотите найти:\n";
	std::cin >> value;
	find<double>(arr, size, value);

	delete[] arr;
	return 0;
}
