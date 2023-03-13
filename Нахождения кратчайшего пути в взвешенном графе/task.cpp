#include "Graph.h"
// поиск кратчайшего расстояния
#define VERYBIGINT 1000000000
int Graph::findMinWayDFS(int from, int to) {
	// Ваш код должен быть здесь 
	bool visited[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		visited[i] = false;
	}
	int min = 0;
	int currentDistance=0;
	depthInner(from, to, visited, min, currentDistance);
	return min;
}
void Graph::depthInner(int current, int to, bool visited[], int& min, int currentDistance) {

	if (current == to) {
		if (min == 0) {
			min = currentDistance;
			currentDistance = currentDistance - matrix[current][to];
		}
		 if (min!=0&&(currentDistance < min)) {
			min = currentDistance;
			currentDistance = currentDistance-matrix[current][to];
			return;
		}
		 else {
			currentDistance = currentDistance-matrix[current][to];
			return;
		}
	}
	visited[current] = true;
	for (int i = 0; i < SIZE; i++)
	{
		if (edgeExists(current, i) && !visited[i]) {
			currentDistance += matrix[current][i];
			depthInner(i, to, visited, min, currentDistance);
		}
	}
	visited[current] = false;
}