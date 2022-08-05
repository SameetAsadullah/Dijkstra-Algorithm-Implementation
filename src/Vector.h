#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector {
	T* data;
	int capacity, size;

public:
	//Constructors
	Vector(int Size = 20) : data(new T[Size]), capacity(Size), size(-1) {
	}

	Vector(const Vector<T>& obj) {
		size = obj.size;
		capacity = obj.capacity;
		data = new T[capacity];

		for (int i = 0; i <= size; i++) {
			data[i] = obj.data[i];
		}
	}

	//Getters
	int Size() {
		return size + 1;
	}

	int Capacity() {
		return capacity;
	}

	//Functions
	void insert(const T& element) {
		if (size == capacity - 1) {
			capacity *= 2;
			T* temp = new T[capacity];

			for (int i = 0; i <= size; i++) {
				temp[i] = data[i];
			}

			delete[] data;
			data = temp;
		}
		size++;
		data[size] = element;
	}

	int find(const T& obj) {
		for (int i = 0; i <= size; i++) {
			if (data[i] == obj) {
				return 1;
			}
		}
		return -1;
	}

	void print() {
		for (int i = 0; i <= size; ++i) {
			cout << data[i];
		}
	}

	//Operators Overloading
	Vector& operator = (const Vector<T>& obj) {
		size = obj.size;
		capacity = obj.capacity;
		data = new T[capacity];

		for (int i = 0; i <= size; i++) {
			data[i] = obj.data[i];
		}
		return *this;
	}

	T& operator[] (int i) {
		return data[i];
	}

	//Destructor
	~Vector() {
		size = -1;
		capacity = 0;
		delete[] data;
	}
};