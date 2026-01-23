#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);
    getchar(); // to "eat" the newline (\n)
    for (int tc = 1; tc <= T; tc++) {
        char arr[1007];
        scanf(" %1000s", arr);
        // fgets(arr, sizeof(arr), stdin);
        // arr[strcspn(arr, "\n")] = '\0';
        int len = strlen(arr);
        printf("Case #%d: ", tc);
        for (int i = 0; i < len; i++) printf("%c", arr[len-1-i]);
        printf("\n");
    }
    return 0;
}