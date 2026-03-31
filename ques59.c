#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findIndex(int* inorder, int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct TreeNode* build(int* inorder, int* postorder, int start, int end, int* postIndex) {
    if (start > end)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[*postIndex];
    root->left = root->right = NULL;

    (*postIndex)--;

    if (start == end)
        return root;

    int inIndex = findIndex(inorder, start, end, root->val);

    root->right = build(inorder, postorder, inIndex + 1, end, postIndex);
    root->left  = build(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct TreeNode* root = build(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}