#include <stdio.h>
#include <string.h>
int main(){
    char s[100001];
    scanf("%s", s);   // read string without spaces

    int left = 0;
    int right = strlen(s) - 1;
    char temp;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    printf("%s", s);
    return 0;
}