#include <stdio.h>
#include <stdlib.h>

#define SIZE 10007

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* hashTable[SIZE];

// Hash function
int hash(int key) {
    return abs(key) % SIZE;
}

// Insert key if not already present
void insert(int key, int value) {
    int idx = hash(key);
    Node* temp = hashTable[idx];

    while (temp) {
        if (temp->key == key)
            return;
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

// Search for key
int search(int key) {
    int idx = hash(key);
    Node* temp = hashTable[idx];

    while (temp) {
        if (temp->key == key)
            return temp->value;
        temp = temp->next;
    }
    return -1;
}

// Function to find max length
int maxLenZeroSum(int arr[], int n) {
    int prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0)
            maxLen = i + 1;

        int prevIndex = search(prefixSum);

        if (prevIndex != -1) {
            int len = i - prevIndex;
            if (len > maxLen)
                maxLen = len;
        } else {
            insert(prefixSum, i);
        }
    }

    return maxLen;
}

// MAIN FUNCTION (important!)
int main() {
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxLenZeroSum(arr, n);

    printf("Longest subarray length with sum 0 = %d\n", result);

    return 0;
}