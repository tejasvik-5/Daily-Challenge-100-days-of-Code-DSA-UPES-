#include <stdio.h>

int canPaint(int boards[], int n, int k, long long maxTime) {
    int painters = 1;
    long long curr = 0;

    for (int i = 0; i < n; i++) {
        if (curr + boards[i] > maxTime) {
            painters++;
            curr = boards[i];

            if (painters > k)
                return 0;
        } else {
            curr += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > low)
            low = boards[i];  
        high += boards[i];    
    }

    while (low < high) {
        long long mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid))
            high = mid;
        else
            low = mid + 1;
    }

    printf("%lld\n", low);
    return 0;
}