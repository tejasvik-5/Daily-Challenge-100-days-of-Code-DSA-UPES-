#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int isComplete(struct Node* root, int index, int n) {
    if (root == NULL)
        return 1;

    if (index >= n)
        return 0;

    return isComplete(root->left, 2 * index + 1, n) &&
           isComplete(root->right, 2 * index + 2, n);
}

int isMinHeap(struct Node* root) {
    if (root->left == NULL && root->right == NULL)
        return 1;

    if (root->right == NULL)
        return root->data <= root->left->data;

    return (root->data <= root->left->data &&
            root->data <= root->right->data &&
            isMinHeap(root->left) &&
            isMinHeap(root->right));
}

int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int checkMinHeap(struct Node* root) {
    int n = countNodes(root);

    if (isComplete(root, 0, n) && isMinHeap(root))
        return 1;
    return 0;
}

struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n)
        return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    if (checkMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}