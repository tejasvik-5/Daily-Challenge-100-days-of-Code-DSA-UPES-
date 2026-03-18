#include <stdio.h>
#include <stdlib.h>

// Definition for binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Queue structure
struct Queue {
    struct TreeNode* data[2000];
    int front, rear;
};

// Queue functions
void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->data[q->front++];
}

// Level Order Traversal
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int** result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));
    *returnSize = 0;

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;

        (*returnColumnSizes)[*returnSize] = size;
        result[*returnSize] = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);

            result[*returnSize][i] = node->val;

            if (node->left)
                enqueue(&q, node->left);

            if (node->right)
                enqueue(&q, node->right);
        }

        (*returnSize)++;
    }

    return result;
}

// MAIN FUNCTION (fixes your error)
int main() {
    // Creating tree: [3,9,20,null,null,15,7]
    struct TreeNode n1 = {3, NULL, NULL};
    struct TreeNode n2 = {9, NULL, NULL};
    struct TreeNode n3 = {20, NULL, NULL};
    struct TreeNode n4 = {15, NULL, NULL};
    struct TreeNode n5 = {7, NULL, NULL};

    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n3.right = &n5;

    int returnSize;
    int* returnColumnSizes;

    int** result = levelOrder(&n1, &returnSize, &returnColumnSizes);

    printf("Level Order Traversal:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}