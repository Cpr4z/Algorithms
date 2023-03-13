#include "Graph.h"
#include <iostream>

#define VERYBIGINT 1000000

Graph::Graph() 
{	for (int i = 0; i < SIZE; i++)
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
bool Graph::are_adj(int v1, int v2) 
{
	return matrix[v1][v2] != 0;
}
void Graph::find_min_dist_floyd() {

	int weight[SIZE][SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == j) {
				weight[i][j] = 0;
			}
			else {
				if(are_adj(i, j)) {
				weight[i][j] = matrix[i][j];
				}
				else {
					weight[i][j] = VERYBIGINT;
				}
			}
		}
	}

	for (int k = 0; k < vertexCount; k++)
	{
		int ck = vertexes[k];
		for (int i = 0; i < vertexCount; i++)
		{
			if (i == k)
				continue;
			int ci = vertexes[i];
			for (int j = 0; j < vertexCount; j++)
			{
				if (j == k)
					continue;
				int cj = vertexes[j];

				if (weight[i][k] + weight[k][j] < weight[i][j]) {
					weight[i][j] = weight[i][k] + weight[k][j];
				}
			}
		}
	}
	for (int  k = 0; k < vertexCount; k++)
	{
		int ck = vertexes[k];

		std::cout << "V" << ck << ":" << weight[0][ck] << ", ";
	}
}