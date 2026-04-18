#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int visited[MAX];
int adj[MAX][MAX];
int n, m;

void dfs(int node) {
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}