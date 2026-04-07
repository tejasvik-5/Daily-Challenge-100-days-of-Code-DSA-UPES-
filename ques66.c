#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int** graph, int* graphSize, bool* visited, bool* recStack) {
    
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < graphSize[node]; i++) {
        int neighbor = graph[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, graphSize, visited, recStack))
                return true;
        }
        
        else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false; 
    return false;
}

void detectCycle(int V, int** graph, int* graphSize) {
    
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, graphSize, visited, recStack)) {
                printf("YES\n");
                return;
            }
        }
    }

    printf("NO\n");
}

int main() {
    int V = 4;

    int** graph = (int**)malloc(V * sizeof(int*));
    int* graphSize = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }

    graph[0][graphSize[0]++] = 1;
    graph[1][graphSize[1]++] = 2;
    graph[2][graphSize[2]++] = 3;
    graph[3][graphSize[3]++] = 1;

    detectCycle(V, graph, graphSize);

    return 0;
}