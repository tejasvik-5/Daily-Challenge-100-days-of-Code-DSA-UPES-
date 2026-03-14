#include <stdio.h>

#define SIZE 100

int queue[SIZE];
int front = 0, rear = -1;

int stack[SIZE];
int top = -1;

void enqueue(int x){
    rear++;
    queue[rear] = x;
}

int dequeue(){
    int x = queue[front];
    front++;
    return x;
}

void push(int x){
    top++;
    stack[top] = x;
}

int pop(){
    int x = stack[top];
    top--;
    return x;
}

int main(){

    int n, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &x);
        enqueue(x);
    }

    /* Move queue → stack */
    for(i = 0; i < n; i++){
        push(dequeue());
    }

    /* Move stack → queue */
    for(i = 0; i < n; i++){
        enqueue(pop());
    }

    /* Print reversed queue */
    for(i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }

    return 0;
}