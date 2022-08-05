#include "Dijkstra.h"

int main() {
	Graph<int, int> g;
	g.insert(1, 2, 5);
	g.insert(1, 3, 7);
	g.insert(2, 3, 1);
	g.insert(3, 4, 1);
	g.findAndDisplayMinCostPath(1, 3);
}