#include <stdio.h>

int accumulate(int n, int arr[n], int res, int idx) {
    if (idx <= n - 1) {
        res += arr[idx];
        return accumulate(n, arr, res, idx + 1);
    }
    else return res;
}

int main (void) {
    int T = 0;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int n = 0;
        scanf("%d", &n);
        
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        printf("Case #%d: %d\n", tc, accumulate(n, arr, 0, 0));
    }
    return 0;
}