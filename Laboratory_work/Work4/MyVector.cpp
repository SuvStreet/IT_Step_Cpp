#include "MyVector.h"
#include<iostream>

size_t MyVector::counterVector = 0;
size_t MyVector::counterRealVector = 0;

MyVector::MyVector() : size(0), capacity(32) {
	arr = new double[32];
	++counterVector;
	++counterRealVector;
}

MyVector::MyVector(const MyVector& myObj) : size(myObj.size), capacity(myObj.capacity) {
	arr = new double[capacity];
	for (size_t i = 0; i < size; ++i) {
		arr[i] = myObj.arr[i];
	}
	++counterVector;
	++counterRealVector;
};

MyVector::MyVector(MyVector&& myObj) : size(myObj.size), capacity(myObj.capacity), arr(myObj.arr) {
	myObj.size = 0;
	myObj.capacity = 0;
	myObj.arr = nullptr;
	++counterVector;
	++counterRealVector;
};

bool MyVector::empty() const {
	if (size == 0) return true;
	return false;
}

size_t MyVector::get_size() const {
	return size;
}

size_t MyVector::get_capacity() const {
	return capacity;
}

void MyVector::push_back(double value) {
	if (size < capacity) arr[size++] = value;
	else {
		double *new_arr = new double[capacity * 2];
		capacity *= 2;
		for (size_t i = 0; i < size; ++i)
			new_arr[i] = arr[i];
		delete[]arr;
		arr = new_arr;
		arr[size] = value;
		size = size + 1;
	}
}

double MyVector::pop_back() {
	if (!empty()) {
		--size;
		return arr[size];
	}
	std::cout << "Vector is empty!\n";
	return 0;
}

double& MyVector::at(int index) {
	if (index < size) {
		return arr[index];
	}
}

void MyVector::print() {
	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
}

MyVector::MyVector(double new_arr[], int new_size) : size(new_size) {
	++counterVector;
	++counterRealVector;
	int counter = new_size / 32;

	arr = new double[(counter + 1) * 32];
	capacity = 32 * (counter + 1);

	for (unsigned int i = 0; i < size; ++i)
		arr[i] = new_arr[i];
}

double MyVector::get_min() const {
	if (!size) {
		std::cout << "Vector is empty!\n";
		return 0;
	}
	double min = arr[0];
	for (size_t i = 0; i < size; ++i) {
		if (arr[i] < min) min = arr[i];
	}
	return min;
}

double MyVector::get_max() const {
	if (!size) {
		std::cout << "Vector is empty!\n";
		return 0;
	}
	double max = arr[0];
	for (size_t i = 0; i < size; ++i) {
		if (arr[i] > max) max = arr[i];
	}
	return max;
}

void MyVector::sort() {
	for (size_t i = size / 2; i > 0; i /= 2) {
		for (size_t j = i, g; j < size; ++j) {
			double temp = arr[j];
			for (g = j; g >= i; g -= i) {
				if (temp < arr[g - i])
					arr[g] = arr[g - i];
				else break;
			}
			arr[g] = temp;
		}
	}
}
