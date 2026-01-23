#include <stdio.h>

int main(void) {
    double a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3;
    scanf("%lf %lf %lf %lf", &a1, &b1, &c1, &d1);
    scanf("%lf %lf %lf %lf", &a2, &b2, &c2, &d2);
    scanf("%lf %lf %lf %lf", &a3, &b3, &c3, &d3);

    printf("%.2lf\n", a1/1 + b1/2 + c1/3 + d1/4 + b1/2 + c1/3 + d1/4 + c1/3 + c1/3 + d1/4 + c1/3 + b1/2 + d1/4 + c1/3 + b1/2 + a1/1);
    printf("%.2lf\n", a2/1 + b2/2 + c2/3 + d2/4 + b2/2 + c2/3 + d2/4 + c2/3 + c2/3 + d2/4 + c2/3 + b2/2 + d2/4 + c2/3 + b2/2 + a2/1);
    printf("%.2lf\n", a3/1 + b3/2 + c3/3 + d3/4 + b3/2 + c3/3 + d3/4 + c3/3 + c3/3 + d3/4 + c3/3 + b3/2 + d3/4 + c3/3 + b3/2 + a3/1);
    return 0;
}