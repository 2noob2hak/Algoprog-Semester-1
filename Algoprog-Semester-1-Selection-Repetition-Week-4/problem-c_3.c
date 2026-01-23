#include <stdio.h>

int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main(void) {
    int T,N;
    int a, Y;

    scanf("%d", &T);
    for (int x = 0; x < T; x++) 
    {
        scanf("%d", &N);
        scanf("%d", &Y);
        for (int n = 1; n < N; n++) 
        {
            scanf("%d", &a);
            Y = gcd(Y, a);
        }   
        printf("Case #%d: %d\n", x + 1, Y);
    }
    return 0;
}