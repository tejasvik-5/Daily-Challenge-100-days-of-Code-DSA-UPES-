#include <stdio.h>

int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];
        } else {
            pages += arr[i];
        }
    }

    return students <= m;
}

int findPages(int arr[], int n, int m) {
    if (m > n)
        return -1;

    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(arr, n, m, mid))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", findPages(arr, n, m));

    return 0;
}