#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    int i, j;
    int isIdentity = 1;   // assume true initially

    // Input matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity condition
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j) {
                if(matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                if(matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
    }
    // Output result
    if(isIdentity == 1)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}