#include <stdio.h>

int main(void) {
    int T;
    int A, B, C, D, E, F;
    scanf("%d", &T);
    
for (int tc = 1; tc <= T; tc++) {
    scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);
    printf("Case #%d: ", tc);
    for (int a = 0; a < A; a++) printf("a");
    for (int b = 0; b < B; b++) printf("s");
    for (int c = 0; c < C; c++) printf("h");
    for (int d = 0; d < D; d++) printf("i");
    for (int e = 0; e < E; e++) printf("a");
    for (int f = 0; f < F; f++) printf("p");
    printf("\n");
}
    return 0;
}