#include "MyVector.h"
#include "Test.h"

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

void MyVector::push_back(double value)
{
	if (size < capacity) arr[size++] = value;
	else
	{
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

double& MyVector::at(int index)
{
	if (index < size) {
		return arr[index];
	}
}

void MyVector::print()
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
}
