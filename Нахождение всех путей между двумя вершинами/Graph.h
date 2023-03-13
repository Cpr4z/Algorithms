#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;
#define SIZE 10

class Graph {
public:
    Graph();
    // добавление вершины
    void addVertex(int vnumber);
    // добавление ребра
    void addEdge(int v1, int v2, int weight);
    int findPathCount(int v1, int v2);
 
    void depthInner(int current, int to, bool visited[], int& countWays);
private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);

    int matrix[SIZE][SIZE]; // матрица смежности

    int vertexes[SIZE]; // хранилище вершин
    int vertexCount; // количество добавленных вершин
};
