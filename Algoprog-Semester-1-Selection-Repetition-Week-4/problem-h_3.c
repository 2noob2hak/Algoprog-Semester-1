#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int T, N, X[1005], tc, in;
    scanf("%d", &T);
    for (tc=0; tc<T; tc++) {
        scanf("%d", &N);
        for (in = 0; in<N; in++) {
            scanf("%d", &X[in]);            
        }
        int minDiff = 1000000000;
        for (int i = 0; i<N-1; i++) {
            int Diff = abs(X[i] - X[i+1]);
            if (Diff < minDiff) minDiff = Diff;
        }
        printf("Case #%d: %d\n", tc + 1, minDiff);
    }
    return 0;
}