#include <stdio.h>

long long F(long long n, int *multiple_3) {
    if (n < 0)
        return 0;
    if (n >= 3 && n % 3 == 0)
        (*multiple_3)++;
    if (n == 0) 
        return 1;
    if (n == 1)
        return 2;
    if (n % 5 == 0)
        return n * 2;
        
    return F(n-1, multiple_3) + n + F(n-2, multiple_3) + n - 2;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int multiple_3 = 0;
        long long N;
        scanf("%lld", &N);
        printf("Case #%d: %lld ", tc, F(N, &multiple_3));
        printf("%d\n", multiple_3);
    }
    return 0;
}