#include "graph.h"
#include <iostream>
void Graph::width(int start) {
	int queue[SIZE]{};//создаем очередь
	int queueCount = 0;
	bool visited[SIZE];
	for (size_t i = 0; i < SIZE; i++)
	{
		visited[i] = false;
	}
	queue[queueCount++] = start;

	while (queueCount > 0) {//пока есть элементы в очереди
		int currentNum = queue[0];
		queueCount--;
		for (int i = 0; i<queueCount; i++)
			queue[i] = queue[i + 1];
		std::cout << "V" << currentNum << ", ";
		visited[currentNum] = true;

		for (int i = 0; i < vertexCount; i++) {
			int vnum = vertexes[i];
			int j = 0;
			for (; j < queueCount; j++) 
				if (queue[j] == vnum)
					break;
			
			if (j < queueCount)
				continue;

			if (are_adj(currentNum, vnum) && !visited[vnum]) {
				queue[queueCount++] = vnum;
			}
		}
	}
 }