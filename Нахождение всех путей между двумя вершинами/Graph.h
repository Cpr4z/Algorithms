#pragma once
#include <iostream>
#include <vector>
#include <list>
using namespace std;
#define SIZE 10

class Graph {
public:
    Graph();
    // ���������� �������
    void addVertex(int vnumber);
    // ���������� �����
    void addEdge(int v1, int v2, int weight);
    int findPathCount(int v1, int v2);
 
    void depthInner(int current, int to, bool visited[], int& countWays);
private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);

    int matrix[SIZE][SIZE]; // ������� ���������

    int vertexes[SIZE]; // ��������� ������
    int vertexCount; // ���������� ����������� ������
};
