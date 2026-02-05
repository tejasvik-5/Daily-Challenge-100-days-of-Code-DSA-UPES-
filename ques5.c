#include <stdio.h>
int main(){
    int p, q;
    int a[1000], b[1000];
    int i = 0, j = 0;
    // Input size of first log
    scanf("%d", &p);
    // Input first sorted array
    for (int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }
    // Input size of second log
    scanf("%d", &q);
    // Input second sorted array
    for (int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }
    // Merge and print in sorted order
    while (i < p && j < q) {
        if (a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }
    // Print remaining elements of first array
    while (i < p) {
        printf("%d ", a[i]);
        i++;
    }
    // Print remaining elements of second array
    while (j < q) {
        printf("%d ", b[j]);
        j++;
    }
    return 0;
}