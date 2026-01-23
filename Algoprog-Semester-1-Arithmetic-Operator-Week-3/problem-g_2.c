#include <stdio.h>

int main(void) {
    int N;
    long long total = 0;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++ ) {
        int damage = 100 + (i-1) * 50;
        total += damage;
    }

    printf("%lld\n", total);
    return 0;
}