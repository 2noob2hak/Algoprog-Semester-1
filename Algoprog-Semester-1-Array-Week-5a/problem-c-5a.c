#include <stdio.h>

int main(void) {
    int T, N;

    // input handling
    scanf("%d", &T);
    for (int tc=0; tc<T; tc++) {
        scanf("%d", &N);
        int arr_matrices1[N][N];
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                scanf("%d", &arr_matrices1[i][j]);
            }
        }
        getchar();

        int arr_matrices2[N][N];
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                scanf("%d", &arr_matrices2[i][j]);
            }
        }
        getchar();

        int arr_matrices3[N][N];
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                scanf("%d", &arr_matrices3[i][j]);
            }
        }

        // compute
        int arr_res1[N][N];
        int arr_res2[N][N];

        // the holy grail formula of any matrix-size multiplication
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                arr_res1[i][j] = 0;
                for (int k=0; k<N; k++) {
                    arr_res1[i][j] += arr_matrices1[i][k]*arr_matrices2[k][j];
                }
            }
        }
    
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                arr_res2[i][j] = 0;
                for (int k=0; k<N; k++) {
                    arr_res2[i][j] += arr_res1[i][k]*arr_matrices3[k][j];
                }
            }
        }

        // output
        printf("Case #%d:\n", tc+1);
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                printf("%d", arr_res2[i][j]);
                if (j < N-1)
                  printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}