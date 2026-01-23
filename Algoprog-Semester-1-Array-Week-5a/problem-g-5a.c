#include <stdio.h>
#include <stdbool.h>

int main(void) {
    // handling input
    int N;
    scanf("%d", &N);
    int arr[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            scanf("%d", &arr[i][j]);
    }

    // checking for same number
    int same_num = false;
    // row check
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            for (int z = y + 1; z < N; z++) {
                if (arr[x][y] == arr[x][z]) {
                    same_num = true;
                    break;
                }
            }
        if (same_num == true) break;
        }
    if (same_num == true) break;
    }
    // column check
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            for (int z = y + 1; z < N; z++) {
                if (arr[y][x] == arr[z][x]) {
                    same_num = true;
                    break;
                }
            }
            if (same_num == true) break;
        }
    if (same_num == true) break;
    }

    // handling output
    if (same_num == true) printf("Nay\n");
    else printf("Yay\n");
    
    return 0;
}