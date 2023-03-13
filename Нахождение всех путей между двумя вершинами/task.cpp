#include <iostream>
#include "Graph.h"
#include <vector>
#include <list>
using namespace std;


// поиск количества путей
int Graph::findPathCount(int from, int to)
// ¬аш код должен быть здесь 
{
    bool visited[SIZE];
    for (int i = 0; i < vertexCount; i++) {
        visited[i] = false;
    }
    int countWays = 0;
    depthInner(from, to, visited, countWays);
    return countWays;

}
void Graph::depthInner(int current, int to, bool visited[], int& countWays) {
    if (current == to) {
        countWays++;
        return;
    }
    visited[current] = true;
    for (int i = 0; i < SIZE; i++) {
        if (edgeExists(current, i) && !visited[i]) {
            depthInner(i, to, visited, countWays);
        }

    }
    visited[current] = false;
}