#pragma once
#include<iostream>
using namespace std;

template<class T, class U>
class Node {
public:
	T adjVertex;
	Node* next;
	U cost;

	Node() :next(NULL) {
	}
};

template<class T, class U>
class List {
private:
	Node<T, U>* head;
	Node<T, U>* cursor;
	T Vertex;

public:
	List(int ignored = 0) {
		head = NULL;
		cursor = NULL;
	}

	void setVertex(T v) {
		Vertex = v;
	}

	T getVertex() const {
		return Vertex;
	}

	Node<T, U>* getHead() {
		return head;
	}

	void insert(const T& newDataItem, const U& c) {
		if (head == NULL) {
			head = new Node<T, U>;
			head->adjVertex = newDataItem;
			head->cost = c;
			cursor = head;
		}

		else {
			cursor = head;
			while (cursor->next != NULL) {
				cursor = cursor->next;
			}

			cursor->next = new Node<T, U>;
			cursor->next->adjVertex = newDataItem;
			cursor->next->cost = c;
			cursor = cursor->next;
		}
	}

	void clear() {
		cursor = head;
		while (cursor != NULL) {
			Node<T, U>* temp = cursor;
			cursor = cursor->next;
			delete temp;
		}
		head = cursor;
	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		return false;
	}

	void Display() {
		Node<T, U>* temp = head;

		while (temp != NULL) {
			cout << "Adjacent Vertix: " << temp->adjVertex << endl;
			cout << "Cost: " << temp->cost << endl << endl;
			temp = temp->next;
		}
	}

	~List() {
		while (head != NULL) {
			Node<T, U>* temp = head;
			head = head->next;
			delete temp;
		}
	}
};
