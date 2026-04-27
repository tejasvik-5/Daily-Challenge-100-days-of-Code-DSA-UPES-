#include <stdio.h>

int integerSqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    int left = 0, right = x;
    int ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (mid * mid == x) {
            return mid;
        }
        else if (mid * mid < x) {
            ans = mid;       
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%d", integerSqrt(x));
    return 0;
}