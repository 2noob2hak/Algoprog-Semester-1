#include <stdio.h>

int main(void) {
    int N, w = 0;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        if (i % 2 != 0) {
            if (N - i != 0) {
                for (int j = 0; j < (N / 2) - w; j++)
                    printf(" ");
                w++;
            }
            for (int k = 0; k < i; k++)
                printf("*");    
        }
        if (i % 2 == 0)
            printf("\n\n");
        if (i == N) 
            printf("\n");
    }
    return 0;
}