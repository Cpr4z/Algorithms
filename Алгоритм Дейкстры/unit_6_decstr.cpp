#include "Graph.h"
#include <iostream>

#define VERYBIGINT 1000000

Graph::Graph() {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j] = 0;
	vertexCount = 0;
}

void Graph::addVertex(int vnumber)
{
	vertexes[vertexCount++] = vnumber;
}
void Graph::addEdge(int v1, int v2, int weight) {
	matrix[v1][v2] = weight;
	matrix[v2][v1] = weight;
}
bool Graph::are_adj(int v1, int v2) {
	return matrix[v1][v2] != 0;
}

void Graph::find_min_dist_decstr(int vfrom) {
	int distances[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		distances[i] = VERYBIGINT;
	}
	distances[vfrom] = 0;

	bool passed[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		passed[i] = false;
	}
	int currentV = vfrom;
	int min_dist = 0;

	while (min_dist != VERYBIGINT) {
		passed[currentV] = true;
		for (int i = 0; i < vertexCount; i++)
		{
			int vi = vertexes[i];
			if (are_adj(vi, currentV) && distances[vi] > distances[currentV] + matrix[vi][currentV]) {
				distances[vi] = distances[currentV] + matrix[vi][currentV];
			}
		}
		min_dist = VERYBIGINT;
		for (size_t i = 0; i < vertexCount; i++)
		{
			int vi = vertexes[i];
			if (!passed[vi] && distances[vi] < min_dist) {
				currentV = vi;
				min_dist = distances[vi];
			}

		}
	}
	for (size_t i = 0; i < vertexCount; i++)
	{
		int vi = vertexes[i];
		std::cout << "V"<< vi <<" "<< distances[vi] << ", ";
	}
}