#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* exp) {
    char* token = strtok(exp, " ");

    while (token != NULL) {

        if (isdigit(token[0])) { 
            push(atoi(token));
        } 
        else { 
            int op2 = pop();
            int op1 = pop();
            int result;

            switch(token[0]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }

            push(result);
        }

        token = strtok(NULL, " ");
    }

    return pop();
}

int main() {
    char exp[100];

    fgets(exp, sizeof(exp), stdin);
    exp[strcspn(exp, "\n")] = 0;

    int result = evaluatePostfix(exp);
    printf("%d\n", result);

    return 0;
}