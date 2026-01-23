#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    for (int tc=1; tc<=T; tc++) {
        long long A = 0, B = 0, result = 0;
        long long place = 1;
        scanf("%lld %lld", &A, &B);
        while (A>0 || B>0) {
            int sum = (A%10 + B%10) % 10;
            result += sum * place;
            place *= 10;
            A /= 10;
            B /= 10;
        }
        printf("Case #%d: %lld\n", tc, result);
    }
    return 0;
}