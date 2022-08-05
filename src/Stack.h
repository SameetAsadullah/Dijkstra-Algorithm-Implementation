#pragma once
#include<iostream>
using namespace std;

template<class T>
class StackNode {
public:
	T data;
	StackNode* next;

	StackNode() :next(NULL) {
	}
};

template<class T>
class Stack {
	StackNode<T>* top;

public:
	Stack(int ignored = 0) :top(NULL) {
	}

	bool isEmpty() {
		if (top == NULL) {
			return true;
		}
		return false;
	}

	StackNode<T>* getTop() {
		return top;
	}

	T TOP() {
		return top->data;
	}

	void push(T dataItem) {
		StackNode<T>* temp = new StackNode<T>;
		temp->data = dataItem;
		temp->next = top;
		top = temp;
	}

	T pop() {
		if (!isEmpty()) {
			T data = top->data;
			StackNode<T>* temp = top;
			top = top->next;
			delete temp;
			return data;
		}
	}

	void clear() {
		while (top != NULL) {
			pop();
		}
	}

	~Stack() {
		clear();
	}
};