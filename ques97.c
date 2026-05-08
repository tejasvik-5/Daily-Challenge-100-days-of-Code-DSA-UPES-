#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Meeting;

int compare(const void *a, const void *b) {
    Meeting *m1 = (Meeting *)a;
    Meeting *m2 = (Meeting *)b;
    return m1->start - m2->start;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index])
            break;

        swap(&heap[parent], &heap[index]);
        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == index)
            break;

        swap(&heap[index], &heap[smallest]);
        index = smallest;
    }
}

void push(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int minMeetingRooms(int start[], int end[], int n) {
    Meeting meetings[n];

    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    qsort(meetings, n, sizeof(Meeting), compare);

    int heap[n];
    int heapSize = 0;

    for (int i = 0; i < n; i++) {

        if (heapSize > 0 && meetings[i].start >= heap[0]) {
            pop(heap, &heapSize);
        }

        push(heap, &heapSize, meetings[i].end);
    }

    return heapSize;
}

int main() {
    int start[] = {900, 940, 950, 1100, 1500, 1800};
    int end[]   = {910, 1200, 1120, 1130, 1900, 2000};

    int n = sizeof(start) / sizeof(start[0]);

    printf("Minimum rooms required = %d", minMeetingRooms(start, end, n));

    return 0;
}