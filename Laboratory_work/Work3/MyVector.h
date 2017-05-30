#pragma once
#include<iostream>

class MyVector
{
	double* arr; // указатель на массив
	size_t size; // размер
	size_t capacity; // ёмкость
public:
	MyVector() : size(0), capacity(32) {
		arr = new double[32];
	}

	MyVector(const MyVector& myObj) : size(myObj.size), capacity(myObj.capacity) {
		arr = new double[capacity];
		for (size_t i = 0; i < size; ++i)
		{
			arr[i] = myObj.arr[i];
		}
	};

	~MyVector() {
		delete [] arr;
	}

	bool empty() const; // проверяет, пуст ли вектор
	size_t get_size() const; // возвращает количество элементов, содержащихся в векторе
	size_t get_capacity() const; // возвращает ёмкость вектора
	double pop_back(); // извлекает из вектора последний элемент; ёмкость вектора не меняется
	void push_back(double value); // добовляет элемент в конец вектора, при необходимости происходит перевыделение памяти
	double& at(int index); // возвращает по ссылке(&) элемент вектора с заданным индексом
	void print(); // печатает все значения, содержащиеся в векторе

};
