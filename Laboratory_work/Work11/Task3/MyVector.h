#pragma once

template<typename T>
class MyVector
{
	T* arr;
	size_t size;
	size_t capacity;
public:
	MyVector();
	MyVector(const MyVector&);
	MyVector(MyVector&&);

	~MyVector() {
		delete[] arr;
	}

	bool empty() const;
	size_t get_size() const;
	size_t get_capacity() const;
	T pop_back();
	void push_back(const T);
	T& at(const int);
	void print();
	void insert(const T, const size_t);
	void resize(size_t);
};

template<typename T>
MyVector<T>::MyVector() : size(0), capacity(2) {
	arr = new double[capacity];
}

template<typename T>
MyVector<T>::MyVector(const MyVector& myObj) : size(myObj.size), capacity(myObj.capacity) {
	arr = new double[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		arr[i] = myObj.arr[i];
	}
};

template<typename T>
MyVector<T>::MyVector(MyVector&& myObj) : size(myObj.size), capacity(myObj.capacity), arr(myObj.arr) {
	myObj.size = 0;
	myObj.capacity = 0;
	myObj.arr = nullptr;
};

template<typename T>
bool MyVector<T>::empty() const {
	return size == 0 ? true : false;
}

template<typename T>
size_t MyVector<T>::get_size() const {
	return size;
}

template<typename T>
size_t MyVector<T>::get_capacity() const {
	return capacity;
}

template<typename T>
void MyVector<T>::push_back(T value)
{
	if (size < capacity) arr[size++] = value;
	else
	{
		T *new_arr = new T[capacity * 2];
		capacity *= 2;
		for (size_t i = 0; i < size; ++i)
			new_arr[i] = arr[i];
		delete[]arr;
		arr = new_arr;
		arr[size] = value;
		size = size + 1;
	}
}

template<typename T>
T MyVector<T>::pop_back() {
	if (!size)std::cout << "Vector is empty!!!";
	else --size;
	return arr[size];
}

template<typename T>
T& MyVector<T>::at(const int index)
{
	if (index < size) {
		return arr[index];
	}
}

template<typename T>
void MyVector<T>::print()
{
	for (size_t i = 0; i < size; ++i) {
		std::cout << arr[i] << std::endl;
	}
}

template<typename T>
void MyVector<T>::insert(const T value, const size_t index) {
	if (index > size) {
		std::cout << "Error!\n";
		return;
	}

	if (size == capacity) {
		T *new_arr = new T[capacity * 2];
		capacity *= 2;
		for (size_t i = 0; i < size; i++)
			new_arr[i] = arr[i];
		delete[]arr;
		arr = new_arr;
		arr[size] = value;
		size = size + 1;
	}

	else if (index == size)
		push_back(value);

	else {
		T *new_arr = new T[capacity];
		for (size_t i = 0; i <= index; ++i)
			new_arr[i] = arr[i];
		new_arr[index + 1] = value;
		for (size_t i = index + 2; i < size; ++i)
			new_arr[i] = arr[i - 1];
		arr = new_arr;
		arr[size] = value;
		size = size + 1;
	}
}

template<typename T>
void MyVector<T>::resize(size_t value) {
	if (value < size) {
		std::cout << "Error!\n";
		return;
	}

	if (value == capacity)
		return;

	T* new_arr = new T[value];
	capacity = value;
	for (size_t i = 0; i < size; ++i)
		new_arr[i] = arr[i];
	delete [] arr;
	arr = new_arr;
}
