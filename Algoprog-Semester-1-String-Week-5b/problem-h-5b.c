#include <stdio.h>

int main(void) {
    int T;
    // handling input
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int N;
        long long K;
        scanf("%d %lld", &N, &K);
        char arr[N+1];
        scanf(" %s", arr);

        // convert
        for (int i = 0; i < N; i++) {
            long long temp = (arr[i] - 'a') + K;
            temp = temp % 26;
            arr[i] = 'a' + temp;
        }
        // handling output
        printf("Case #%d: %s\n", tc, arr);
    }
    return 0;
}