#pragma once

class MyVector
{
	double* arr;
	size_t size;
	size_t capacity;
	static size_t counterVector;
	static size_t counterRealVector;
public:
	MyVector();
	MyVector(const MyVector&);
	MyVector(MyVector&&);

	~MyVector() {
		delete[] arr;
		counterVector -= 1;
	}

	bool empty() const;
	size_t get_size() const;
	size_t get_capacity() const;
	double pop_back();
	void push_back(double value);
	double& at(int index);
	void print();
	
	MyVector(double [], int);

	static size_t getCounterVector()
	{
		return counterVector;
	}

	static size_t getCounterRealVector()
	{
		return counterRealVector;
	}

	double get_min() const;
	double get_max() const;
	void sort();
};
