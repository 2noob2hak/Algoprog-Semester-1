#include <stdio.h>
#include <string.h>

void reverse(char *string, int in, int len) {
    if (in >= len)
        return;
    
    char temp;
    temp = string[in];
    string[in] = string[len];
    string[len] = temp;

    reverse(string, in + 1, len - 1);
}

int main(void) {
    int T, len;
    scanf("%d ", &T);

    for(int tc = 1; tc <= T; tc++) {
        char string[1005];
        fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = '\0';
        len = strlen(string) - 1;
        
        reverse(string, 0, len);

        printf("Case #%d: %s\n", tc, string);
    }
    return 0;
}
