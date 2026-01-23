#include <stdio.h>

int main(void) {
    int T;
    // handling input
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int N, M;
        long long res = 0;
        scanf("%d %d", &N, &M);
        for (int i = 0; i<N; i++) {
            long long arr[M];
            long long temp = 0;
            for (int j = 0; j<M; j++) 
                scanf("%lld", &arr[j]);
            // compute
            for (int k=0; k < M; k++) {
                if (arr[k] > temp)
                    temp = arr[k];
            }
            res += temp; 
        }
        // handling output
        printf("Case #%d: %lld\n", tc, res);
    }
    return 0;
}