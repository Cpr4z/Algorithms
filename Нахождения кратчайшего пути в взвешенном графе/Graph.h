#pragma once


#define SIZE 10

class Graph {
public:
    Graph();
    // ���������� �������
    void addVertex(int vnumber);
    // ���������� �����
    void addEdge(int v1, int v2, int weight);
    // �������� �������
    void delVertex(int vnumber);
    // �������� �����
    void delEdge(int v1, int v2);
    //����� ���������� �����
    int findMinWayDFS(int v1, int v2);

    void depthInner(
        int current, int to, bool visited[], int& min, int currentDistance);

    int dummy1(int v1, int v2);
    void dummy2(void** param);
private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);

    int matrix[SIZE][SIZE]; // ������� ���������

    int vertexes[SIZE]; // ��������� ������
    int vertexCount; // ���������� ����������� ������
};
