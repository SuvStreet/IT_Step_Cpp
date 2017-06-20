#pragma once

template<typename T>
class Stack
{
	T* stack;
	size_t size;
	size_t maxSize;
public:
	Stack();
	Stack(const Stack&);
	Stack(Stack&&);

	~Stack() { delete[] stack; };

	bool empty() const; // проверяет, пуст ли стек
	size_t getSize() const; // возвращает количество элементов в стеке
	void push(const T& x); // добавляет элемент в стек
	T top(); // удаляет элемент из стека
	void pop(); // показывает значение вершины стека

	Stack& operator=(const Stack&);
	Stack& operator=(Stack&&);

	bool operator==(const Stack&); // проверяет, равны ли два стека
	bool operator!=(const Stack&); // проверяет, различны ли два стека
};

template<typename T>
Stack<T>::Stack() : size(0), maxSize(2) { stack = new T[maxSize]; };

template<typename T>
Stack<T>::Stack(const Stack& myObj) : size(myObj.size), maxSize(myObj.maxSize) {
	stack = new T[maxSize];
	for (size_t i = 0; i < size; ++i) {
		stack[i] = myObj.stack[i];
	}
}

template<typename T>
Stack<T>::Stack(Stack&& myObj) : size(myObj.size), maxSize(myObj.maxSize), stack(myObj.stack) {
	myObj.size = 0;
	myObj.maxSize = 0;
	myObj.stack = nullptr;
}

template<typename T>
bool Stack<T>::empty() const {
	return size == 0 ? true : false;
}

template<typename T>
size_t Stack<T>::getSize() const {
	return size;
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& newObj) {
	if (this == &newObj)
		return *this;

	delete [] stack;
	stack = new T[newObj.maxSize];
	for (size_t i = 0; i < maxSize; ++i) {
		stack[i] = newObj.stack[i];
	}
	size = newObj.size;
	maxSize = newObj.maxSize;
	return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator=(Stack&& newObj) {
	if (this == &newObj)
		return *this;

	delete [] stack;
	stack = newObj.stack;
	size = newObj.size;
	maxSize = newObj.maxSize;

	newObj.size = 0;
	newObj.maxSize = 0;
	newObj.stack = nullptr;
	return *this;
}

template<typename T>
bool Stack<T>::operator==(const Stack& newSteck) {
	if (size != newSteck.size) return false;
	for (size_t i = 0; i < maxSize; ++i) {
		if (stack[i] != newSteck.stack[i]) return false;
	}
	return true;
}

template<typename T>
bool Stack<T>::operator!=(const Stack& newSteck) {
	if (size == newSteck.size) return false;
	for (size_t i = 0; i < maxSize; ++i) {
		if (stack[i] == newSteck.stack[i]) return false;
	}
	return true;
}

template<typename T>
T Stack<T>::top() {
	return stack[size - 1];
}

template<typename T>
void Stack<T>::pop() {
	if (!empty()) --size;
}

template<typename T>
void Stack<T>::push(const T& x) {
	if (size < maxSize) {
		stack[size] = x;
		size++;
	}
	else {
		T* newStack = new T[maxSize * 2];
		for (size_t i = 0; i < maxSize; ++i) {
			newStack[i] = stack[i];
		}
		newStack[size] = x;
		size++;

		delete[] stack;
		stack = newStack;
		maxSize *= 2;
	}
}
