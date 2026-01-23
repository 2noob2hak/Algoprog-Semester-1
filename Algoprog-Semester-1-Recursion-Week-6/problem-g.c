#include <stdio.h>

void fibo_string (char arr[2], int n) {
    if (n == 0 || n == 1) {
        printf("%c", arr[n]);
        return;
    }

    fibo_string(arr, n - 1);
    fibo_string(arr, n - 2);

}

int main (void) {
    int T = 0;
    scanf("%d", &T); getchar();

    for (int tc = 1; tc <= T; tc++) {
        int n = 0;        
        char arr[2];
        scanf("%d %c %c", &n, &arr[0], &arr[1]); getchar(); 

        printf("Case #%d: ", tc);
        fibo_string(arr, n);
        printf("\n");
    }
    return 0;
}