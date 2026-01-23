#include <stdio.h>

int main(void) {
    int x, y, k, t;
    scanf("%d %d %d", &x, &y, &k);

    if (k - x == y - k && x <= k && y >= k) {
        t = k - x;
        printf("%d\n", t);
    } else {
        printf("-1\n");
    }
    return 0;
}