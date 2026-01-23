#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc = 0; tc < T; tc++) {
        char s[507];
        scanf("%s", s);
        int len = strlen(s);
        int yes = 0;
        
        for (int i=0; i<len/2; i++) {
            if (s[i] == s[len-i-1]) {
                yes++;
            }
        }
        printf("Case #%d: ", tc + 1);
        if (yes == (strlen(s) / 2)) printf("Yay, it's a palindrome\n");
        else printf("Nah, it's not a palindrome\n");
    }
    return 0;
}