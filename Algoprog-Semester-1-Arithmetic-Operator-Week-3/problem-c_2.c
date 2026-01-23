#include <stdio.h>
#include <math.h>

int main() {
    int a;
    double c, b;
    scanf("%d %lf", &a, &b);

    c = a * pow(1 + b/100, 3);

    printf("%.2lf\n", c);
    return 0;
}
