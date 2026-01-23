#include <stdio.h>

int till_one (int n) {
    if (n == 1) {
        return 1;
    }

    if (n % 2 != 0 && n != 1){
        return till_one(n - 1) + till_one(n + 1);
    }

    else
        return till_one(n / 2);
}

int main (void) {
    int T = 0;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int n = 0;
        scanf("%d", &n);
        int result = till_one(n);
        printf("Case #%d: %d\n", tc, result);
    }
    return 0;
}