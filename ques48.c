#include <stdio.h>
#include <stdlib.h>   // for NULL

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    if (root->left != NULL) {
        if (root->left->left == NULL && root->left->right == NULL) {
            sum += root->left->val;
        } else {
            sum += sumOfLeftLeaves(root->left);
        }
    }

    sum += sumOfLeftLeaves(root->right);

    return sum;
}

// Optional: create a simple tree to test
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    // Example: [3,9,20,null,null,15,7]
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Sum of left leaves = %d\n", sumOfLeftLeaves(root));

    return 0;
}