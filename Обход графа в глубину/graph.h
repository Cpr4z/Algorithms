#pragma once
#ifndef __GRAPH__
#define __GRAPH__

#define SIZE 10

class Graph {
public:
	Graph();
	void addVertex(int vnumber);
	void addEdge(int v1, int v2, int weight = 1);
	void width(int start);
	void depth(int start);
private:
	bool are_adj(int v1, int v2);
	void depthInner(int current, bool visited[]);
	int matrix [SIZE][SIZE];
	int vertexes [SIZE];
	int vertexCount;



};
#endif