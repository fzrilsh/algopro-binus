#include <stdio.h>

int main(){
    double p, m, d;

    scanf("%lf %lf %lf", &p, &m, &d);
    printf("%.2f\n", (p * 0.2) + (m * 0.3) + (d * 0.5));

    return 0;
}