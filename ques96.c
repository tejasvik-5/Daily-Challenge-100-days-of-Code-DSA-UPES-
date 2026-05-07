#include <stdio.h>

long long mergeSort(int a[], int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    long long count = 0;

    count += mergeSort(a, left, mid);
    count += mergeSort(a, mid + 1, right);

    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];

            count += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {
        temp[k++] = a[j++];
    }

    for (int x = 0; x < k; x++) {
        a[left + x] = temp[x];
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long ans = mergeSort(a, 0, n - 1);

    printf("%lld", ans);

    return 0;
}