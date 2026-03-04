#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

int main() {
    int n, m, i, value;

    scanf("%d", &n);

    // Push n elements
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform m pops
    for (i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack from top to bottom
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}