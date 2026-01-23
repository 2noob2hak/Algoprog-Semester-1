#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int arr[N],A[N],B[N];

    for (int i=0; i<N; i++) 
        scanf("%d", &A[i]);

    for (int i=0; i<N; i++) 
        scanf("%d", &B[i]);
    
    for (int i=0; i<N; i++) 
        arr[A[i]] = B[i];

    for (int i=0; i<N; i++) {
        printf("%d", arr[i]);
        if (i < N - 1) printf(" ");
    }
    printf("\n");
    return 0;
}