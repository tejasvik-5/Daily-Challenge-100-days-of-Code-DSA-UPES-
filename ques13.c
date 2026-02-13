#include <stdio.h>
int main(){
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[r][c];
    // Input matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    // Spiral Traversal
    while(top <= bottom && left <= right) {

        // Left → Right (Top Row)
        for(int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Top → Bottom (Right Column)
        for(int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;
        // Right → Left (Bottom Row)
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }
        // Bottom → Top (Left Column)
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
    return 0;
}