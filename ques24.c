#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, key, value;

    struct Node *head = NULL, *temp = NULL, *prev = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Create linked list
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    // Input key to delete
    scanf("%d", &key);

    temp = head;
    prev = NULL;

    // Traverse to find first occurrence
    while (temp != NULL) {
        if (temp->data == key) {

            // Case 1: If head needs to be deleted
            if (prev == NULL) {
                head = temp->next;
            }
            // Case 2: Middle or last node
            else {
                prev->next = temp->next;
            }

            free(temp);
            break;  // delete only first occurrence
        }

        prev = temp;
        temp = temp->next;
    }
    // Print updated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}