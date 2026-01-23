#include <stdio.h>

int main(void) {
    int T,X,tc,i2,i1,s;
    scanf("%d", &T);
    for (tc=0; tc<T; tc++) {
        scanf("%d", &X);
        for (i1=1; i1<=X;i1++) {
            for (s=0;s<X-i1;s++) {
                printf(" ");
            }
            for (i2=0; i2<2*i1-1; i2++) {
                printf("*");
            }
        printf("\n");
        }
            
    }
    return 0;
}