#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int cmp(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;
    return x->start - y->start;
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter start and end of interval %d: ", i + 1);
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), cmp);

    printf("Merged intervals:\n");

    int start = arr[0].start;
    int end = arr[0].end;

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= end) {
            if (arr[i].end > end)
                end = arr[i].end;
        } else {
            printf("[%d, %d]\n", start, end);
            start = arr[i].start;
            end = arr[i].end;
        }
    }

    printf("[%d, %d]\n", start, end);

    return 0;
}