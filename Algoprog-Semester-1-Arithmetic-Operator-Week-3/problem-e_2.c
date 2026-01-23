#include <stdio.h>

int main(void) {
    float a, b;
    double c;

    scanf("%f %f", &a, &b);
    c = b / a * 100;
    printf("%.4lf%%\n", c);
    return 0;
}