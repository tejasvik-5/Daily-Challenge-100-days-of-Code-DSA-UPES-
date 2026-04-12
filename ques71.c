#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int index = hash(key, m);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == EMPTY) {
            table[newIndex] = key;
            return;
        }
    }

    printf("Hash table full\n");
}

void search(int table[], int m, int key) {
    int index = hash(key, m);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[newIndex] == EMPTY) {
            break;  // stop early if empty slot
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];

    // initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(table, m, key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(table, m, key);
        }
    }

    return 0;
}