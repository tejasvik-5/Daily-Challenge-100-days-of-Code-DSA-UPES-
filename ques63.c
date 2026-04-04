#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

void dfs(struct Node* adj[], int visited[], int s) {
    printf("%d ", s);
    visited[s] = 1;

    struct Node* temp = adj[s];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            dfs(adj, visited, neighbor);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d", &n);  
    scanf("%d", &m);  

    struct Node* adj[MAX] = {NULL};
    int visited[MAX] = {0};

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int s;
    scanf("%d", &s);   

    printf("DFS Traversal: ");
    dfs(adj, visited, s);

    return 0;
}