#include <stdio.h>
#include <string.h>

char encrypt(char c) {
    if (strchr("ABCD", c)) return 'A';
    if (strchr("EFGH", c)) return 'E';
    if (strchr("IJKLMN", c)) return 'I';
    if (strchr("OPQRST", c)) return 'O';
    if (strchr("UVWXYZ", c)) return 'U';
    return c;
}

int key(char c) {
    if (strchr("AEIOU", c)) return 0;
    if (strchr("ABCD", c)) return c - 'A';
    if (strchr("EFGH", c)) return c - 'E';
    if (strchr("IJKLMN", c)) return c - 'I';
    if (strchr("OPQRST", c)) return c - 'O';
    if (strchr("UVWXYZ", c)) return c - 'U';
    return 0;
}

int main(void) {
    int T;
    // handling input
    scanf("%d", &T);
    for (int tc=0; tc<T; tc++) {
        char message[1005];
        scanf("%s", message);
        // handling output
        printf("Case #%d:\n", tc + 1);
        // encryption
        for (int i=0; message[i]; i++) { // note: message[i] was set as the condition bc while it was not 0 or \0 means it's true(non zero)
            printf("%c", encrypt(message[i]));
        }
        printf("\n");
        // key
        for (int i=0; message[i]; i++) {
            printf("%d", key(message[i]));
        }
        printf("\n");
    }
    return 0;
}