#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int length(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = length(head1);
    int len2 = length(head2);
    
    while (len1 > len2) { head1 = head1->next; len1--; }
    while (len2 > len1) { head2 = head2->next; len2--; }
    
    while (head1 && head2) {
        if (head1->data == head2->data)
            return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

struct Node* buildList(int n) {
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        struct Node* node = newNode(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* head1 = buildList(n);
    scanf("%d", &m);
    struct Node* head2 = buildList(m);
    
    struct Node* inter = getIntersection(head1, head2);
    if (inter) printf("%d\n", inter->data);
    else printf("No Intersection\n");
    
    return 0;
}