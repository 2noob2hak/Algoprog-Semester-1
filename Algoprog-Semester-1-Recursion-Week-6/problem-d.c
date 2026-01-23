#include <stdio.h>
#include <string.h>

int count = 0;
int mark_arr[105][105];

void flood (int a, int b, char arr[a][b], int idx1, int idx2) {
    if (idx1 < 0 || idx1 >= a || idx2 < 0 || idx2 >= b)
    return;
    
    if (arr[idx1][idx2] == '#' || mark_arr[idx1][idx2] == 1)
    return;

    mark_arr[idx1][idx2] = 1;
    
    if (arr[idx1][idx2] == '.') {
        count++;    
    }

    flood(a, b, arr, idx1 - 1, idx2);
    flood(a, b, arr, idx1 + 1, idx2);
    flood(a, b, arr, idx1, idx2 - 1);
    flood(a, b, arr, idx1, idx2 + 1);
}

int main(void) {
    int T = 0;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        count = 0;
        for (int i = 0; i < 105; i++)
            for (int j = 0; j < 105; j++)
                mark_arr[i][j] = 0;

        int a, b;
        scanf("%d %d", &a, &b);
        char arr[a][b];
        
        int source1 = 0, source2 = 0;
        for (int i = 0; i < a; i++) {
            scanf("%100s", arr[i]);
            for (int j = 0; j < b; j++) {
                if (arr[i][j] == 'S') {
                    source1 = i;
                    source2 = j;
                }
            }
        }

        flood(a, b, arr, source1, source2);
        printf("Case #%d: %d\n", tc, count);
    }
    return 0;
}