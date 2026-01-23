#include <stdio.h>

int main(void) {
    double a, b;
    scanf("%lf %lf", &a, &b);
    double diff = a - b;
    double percent = (diff / a) * 100;
    printf("%.2lf%%\n", percent);
    return 0;
}