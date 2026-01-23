#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc=0; tc<T; tc++) {
        char s[1000007];
        scanf("%s", s);
        char alphabet[26] = {0}; // no really as an index for alphabet, just checklists if the 
        int distinct = 0;
    
        for (int i=0; s[i] != '\0'; i++) {
            int index = s[i] - 'a'; // this is the trick to sort abcd correctly as 0123
            if (!alphabet[index]) {
                alphabet[index] = 1;
                distinct++;
            }
        }

        printf("Case #%d: ", tc + 1);
        if (distinct % 2 == 0) printf("Yay\n");
        else printf("Ewwww\n");
    }
    return 0;
}