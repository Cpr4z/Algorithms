#include <iostream>
#include "Graph.h"
int main() {
	Graph g;
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);
    g.addVertex(8);

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(4, 3, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(4, 7, 1);
    g.addEdge(3, 6, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(3, 8, 1);
    g.addEdge(5, 8, 1);
    g.addEdge(8, 6, 1);
    g.addEdge(7, 6, 1);

	cout<<g.findPathCount(0, 2);
	return 0;


}