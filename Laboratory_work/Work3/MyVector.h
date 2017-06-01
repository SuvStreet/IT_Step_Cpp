#pragma once
#include<iostream>

class MyVector
{
	double* arr; // указатель на массив
	size_t size; // размер
	size_t capacity; // ёмкость
public:
	MyVector();
	MyVector(const MyVector&); //конструктор копирования
	MyVector(MyVector&&); // конструктор перемещения

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
