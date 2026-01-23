#include <stdio.h>

int main(void) {
    int T, N, X, tc;
    scanf("%d", &T);
    for (tc=0;tc<T;tc++) {
        scanf("%d %d", &N, &X);
        int front_flip = X/2;
        int back_flip = (N/2 - X/2);
        int minimum_flip = (front_flip < back_flip) ? front_flip : back_flip;
        printf("Case #%d: %d\n", tc + 1, minimum_flip);
    }
    return 0;
}