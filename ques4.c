#include <stdio.h>
int main(){
    int n;
    int arr[1000];
    int left, right, temp;
    // Input size
    scanf("%d", &n);
    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Two-pointer reversal
    left = 0;
    right = n - 1;
    while (left < right) {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
    // Print reversed array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}