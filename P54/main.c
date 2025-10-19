#include <stdio.h>

int main(){
    double x, y;

    scanf("%lf %lf", &x, &y);
    for (int i = 0; i < 3; i++) {
        x = x + (x * (y / 100.0));
    }

    printf("%.2f\n", x);
    return 0;
}