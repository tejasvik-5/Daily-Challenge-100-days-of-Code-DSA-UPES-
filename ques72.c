#include <stdio.h>
#include <string.h>

char firstRepChar(char *s) {
    int seen[26] = {0};  // initialize all to 0

    for (int i = 0; s[i] != '\0'; i++) {
        if (seen[s[i] - 'a'] == 1) {
            return s[i];  // first repeated character
        }
        seen[s[i] - 'a'] = 1;
    }

    return '#';  // if no repeated character
}

int main() {
    char s[1000];
    scanf("%s", s);

    char result = firstRepChar(s);

    if (result == '#')
        printf("No repeated character\n");
    else
        printf("%c\n", result);

    return 0;
}