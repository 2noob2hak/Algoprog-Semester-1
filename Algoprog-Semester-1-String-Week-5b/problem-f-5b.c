#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        char arr[1007];
        int M;
        scanf("%s", arr);
        scanf("%d", &M);
        int len = strlen(arr);

        for (int i=0; i<M; i++) {
            char a, b;
            scanf(" %c %c", &a, &b);

            for (int j=0; j<len; j++) {
                if (arr[j] == a)
                    arr[j] = b;
            }
        }        
        printf("Case #%d: %s", tc, arr);
        printf("\n");
    }
    return 0;
}