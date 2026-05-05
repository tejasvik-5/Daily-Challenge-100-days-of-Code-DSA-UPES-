#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int *freq = (int *)calloc(max + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        freq[i] = freq[i] + freq[i - 1];
    }

    int *output = (int *)malloc(n * sizeof(int));

    for (int i = n - 1; i >= 0; i--) {
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(freq);
    free(output);
}

int main() {
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}