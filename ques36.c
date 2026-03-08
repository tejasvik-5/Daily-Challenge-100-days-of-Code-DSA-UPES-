#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;
int size;

int isFull() {
    return (front == (rear + 1) % size);
}

int isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % size;
    }
}

void display() {
    if (isEmpty()) return;

    int i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % size;
    }
}

int main() {
    int n, m;

    scanf("%d", &n);
    size = n;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}