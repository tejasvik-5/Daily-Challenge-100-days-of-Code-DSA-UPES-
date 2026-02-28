#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n, i;
    scanf("%d", &n);

    if(n <= 0)
        return 0;

    struct node *head = NULL, *temp = NULL, *newnode;

    // Creating Circular Linked List
    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Make list circular
    temp->next = head;

    // Traversal
    struct node *ptr = head;

    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != head);

    return 0;
}