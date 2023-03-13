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

    g.addEdge(0, 2, 13);
    g.addEdge(0, 4, 21);
    g.addEdge(0, 5, 27);
    g.addEdge(2, 3, 82);
    g.addEdge(2, 4, 77);
    g.addEdge(4, 1, 43);
    g.addEdge(4, 5, 11);
    g.addEdge(5, 1, 38);

    std::cout<<g.findMinWayDFS(0, 4);
    return 0;
}