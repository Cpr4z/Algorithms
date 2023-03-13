#include "graph.h"
#include <iostream>

void Graph::depth(int start) {
	bool visited[SIZE];

	for (int  i = 0; i < SIZE; i++)
	{
		visited[i] = false;
	}
	depthInner(start, visited);

}
void Graph::depthInner(int current, bool visited[]) {
	std::cout << "V" << current << ", ";
	visited[current] = true;
	for (int i = 0; i < vertexCount; i++)
	{	
		int vnum = vertexes[i];
		if (are_adj(current,vnum) && !visited[vnum]) {
			depthInner(vnum, visited);
		}
	}
}
