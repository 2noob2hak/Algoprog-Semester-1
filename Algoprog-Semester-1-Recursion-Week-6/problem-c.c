#include <stdio.h>

void tree (int arr[], int count, int idx, int n) {
    count += arr[idx];
    
    // check left first bc if left branch didn't exist then so will right branch
    if (idx * 2 <= n) {
        tree(arr, count, idx * 2, n);
        if(idx * 2 + 1 <= n) {
            tree(arr, count, idx * 2 + 1, n);
        }
    } else {
        printf("%d\n", count);
        return;
    }
}

int main(void) {
    int T = 0;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int n = 101;
        scanf("%d", &n);
        int arr[n+1];

        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
            
        printf("Case #%d:\n", tc);
        tree(arr, 0, 1, n);
    }
    return 0;
}