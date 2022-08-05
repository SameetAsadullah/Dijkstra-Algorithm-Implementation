#pragma once
#include <iostream>
#include <string>
#include "Vector.h"
#include "List.h"
#include "Stack.h"
using namespace std;

template<class T, class U>
class costInfo {	//Structure to store minimum cost and time values
public:
	U cost;
	T parent;
	T adjVertex;
	U vertexCost;

	costInfo() : cost(99999999), parent(0) {
	}
};

template<class T, class U>
class Graph {
	Vector<List<T, U>> adjList;
	int vertices;

	int getVertex_num(T Vertex) { //Func to get index of source in adjList
		for (int i = 0; i < vertices; i++) {
			if (adjList[i].getVertex() == Vertex) {
				return i;
			}
		}
		return -1;
	}

	int minimum(costInfo<T, U> array[], bool set[])	//Func to calculate minimum value for dijkstra
	{
		U min = 99999999;
		int min_index = 0;
		for (int v = 0; v < vertices; v++)
		{
			if (set[v] == 0 && array[v].cost <= min)
			{
				min = array[v].cost;
				min_index = v;
			}
		}
		return min_index;
	}

	Node<T, U>* getAdjVertexLocation(T Vertex, int dest)	//Func to get links of source
	{
		int a = getVertex_num(Vertex);
		Node<T, U>* temp = adjList[a].getHead();
		if (a != -1) {
			for (int i = 1; temp != NULL && i <= dest; i++)
				temp = temp->next;
			return temp;
		}
		temp = NULL;
		return temp;

	}

	double getCost(costInfo<T, U>* costs, T adjVertex) {
		for (int i = 0; i < vertices; i++) {
			if (costs[i].adjVertex == adjVertex) {
				return costs[i].cost;
			}
		}
	}

	int getCostArrayIndex(T adjVertex, costInfo<T, U>* costs) {
		for (int i = 0; i < vertices; i++) {
			if (costs[i].adjVertex == adjVertex) {
				return i;
			}
		}
	}

public:
	Graph() : vertices(0) {
	}

	int getTotalVertices() const {
		return vertices;
	}

	void insertVertex(T Vertex) {
		if (vertices == 0) {
			List<T> newList;
			adjList.insert(newList);
			adjList[0].setVertex(Vertex);
			vertices++;
		}

		else {
			int i = 0;
			for (i = 0; i < vertices; i++) {
				if (adjList[i].getVertex() == Vertex) {
					return;
				}
			}

			List<T> newList;
			adjList.insert(newList);
			adjList[i].setVertex(Vertex);
			vertices++;
		}
	}

	void insert(T Vertex, T adjVertex, U cost) {
		int i = 0;

	J1:
		for (i = 0; i < vertices; i++) {
			if (adjList[i].getVertex() == Vertex) {
				break;
			}
		}

		if (i == vertices) {
			List<T, U> newList;
			adjList.insert(newList);
			adjList[i].setVertex(Vertex);
			vertices++;
			goto J1;
		}

		else {
			adjList[i].insert(adjVertex, cost);
		}

		for (i = 0; i < vertices; i++) {
			if (adjList[i].getVertex() == adjVertex) {
				break;
			}
		}

		if (i == vertices) {
			List<T, U> newList;
			adjList.insert(newList);
			adjList[i].setVertex(adjVertex);
			vertices++;
		}
	}

	void display(T Vertex) {
		for (int i = 0; i < vertices; i++) {
			if (adjList[i].getVertex() == Vertex) {
				adjList[i].Display();
			}
		}
	}

	costInfo<T, U>* dijkstra(T Vertex) {
		costInfo<T, U>* costs = new costInfo<T, U>[vertices];
		bool* Set = new bool[vertices];

		for (int i = 0; i < vertices; i++) {
			Set[i] = 0;
			costs[i].adjVertex = adjList[i].getVertex();
		}

		costs[getVertex_num(Vertex)].cost = 0;

		for (int i = 0; i < vertices - 1; i++) {
			int index = minimum(costs, Set);
			Set[index] = 1;

			for (int v = 0; v < vertices; v++)
			{
				Node<T, U>* Location = getAdjVertexLocation(costs[index].adjVertex, v);

				if (Location && costs[index].cost + getAdjVertexLocation(costs[index].adjVertex, v)->cost <= getCost(costs, getAdjVertexLocation(costs[index].adjVertex, v)->adjVertex))
				{
					int j = getCostArrayIndex(getAdjVertexLocation(costs[index].adjVertex, v)->adjVertex, costs);
					costs[j].cost = costs[index].cost + getAdjVertexLocation(costs[index].adjVertex, v)->cost;
					costs[j].parent = costs[index].adjVertex;
					costs[j].vertexCost = getAdjVertexLocation(costs[index].adjVertex, v)->cost;
				}

				if (!Location) {
					break;
				}
			}
		}
		delete[] Set;
		return costs;
	}

	void findAndDisplayMinCostPath(T Vertex, T adjVertex) {
		costInfo<T, U>* costs = dijkstra(Vertex);
		Stack<T> temp;
		Stack<U> temp2;
		T temp1 = -1;
		U temp3;
		T temp4 = adjVertex;

		while (Vertex != adjVertex) {
			for (int i = 0; i < vertices; i++) {
				if (costs[i].adjVertex == adjVertex) {
					if (costs[i].parent != 0) {
						temp.push(costs[i].adjVertex);
						temp2.push(costs[i].vertexCost);
						adjVertex = costs[i].parent;
						break;
					}
				}

				if (i == vertices - 1) {
					temp1 = Vertex;
				}
			}
		}

		while (!temp.isEmpty() && !temp2.isEmpty()) {
			temp1 = temp.pop();
			temp3 = temp2.pop();
			cout << "Vertex " << Vertex << " to " << temp1 << " with cost: " << temp3 << endl;
			Vertex = temp1;
		}
		cout << "Total Minimum Cost: " << costs[getCostArrayIndex(temp4, costs)].cost << endl;
	}
};