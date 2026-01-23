#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);
        char arr[N+1];
        scanf(" %[^\n]", arr);

        char arr_sorted[N+1];
        int in = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] >= 'a' && arr[i] <= 'z') {
                arr_sorted[in] = arr[i];
                in++;
            }
        }
        arr_sorted[in] = '\0';
        printf("Case #%d: %s\n", tc, arr_sorted);
    }
    return 0;
}