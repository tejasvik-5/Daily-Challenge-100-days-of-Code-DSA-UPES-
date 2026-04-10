#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100

// Adjacency list node
typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAXN];

// Add edge
void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Min Heap
typedef struct {
    int node, dist;
} Pair;

Pair heap[1000];
int size = 0;

void swap(Pair* a, Pair* b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < size && heap[l].dist < heap[smallest].dist)
        smallest = l;
    if (r < size && heap[r].dist < heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void push(int node, int dist) {
    heap[size].node = node;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

Pair pop() {
    Pair top = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return top;
}

int isEmpty() {
    return size == 0;
}

// Dijkstra Function
void dijkstra(int n, int src) {
    int dist[MAXN];

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (!isEmpty()) {
        Pair p = pop();
        int u = p.node;

        if (p.dist > dist[u]) continue;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("Node %d: INF\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }
}

// Example usage
int main() {
    int n = 5;

    for (int i = 0; i < n; i++) adj[i] = NULL;

    addEdge(0, 1, 2);
    addEdge(0, 2, 4);
    addEdge(1, 2, 1);
    addEdge(1, 3, 7);
    addEdge(2, 4, 3);
    addEdge(3, 4, 1);

    dijkstra(n, 0);

    return 0;
}