#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int R; 
        char arr[1005] = {0};
        scanf ("%d %1000s", &R, arr); 
        int len = strlen(arr);

        for (int i = 0; i < R; i++) {
            int a = 0, b = 0;
            char temp;
            scanf("%d %d", &a, &b); // a is the leftmost index and b is righmost index.
            // convert to 0-based
            a--;
            b--;

            while (a < b) {
                temp = arr[a];
                arr[a] = arr[b];
                arr[b] = temp;
                a++;
                b--;
            } 
        }
        printf("Case #%d: ", tc);
        for (int j = 0; j < len; j++) {
            printf("%c", arr[j]);
        }
        printf("\n");
    }

    return 0;
}