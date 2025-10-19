#include <stdio.h>

int main(){
    double a, b, c, d, result[3];


    for (int x = 0; x < 3; x++)
    {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        result[x] = (a / 1 * 2) + (b / 2 * 4) + (c / 3 * 6) + (d / 4 * 4);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%.2f\n", result[i]);
    }
    
    return 0;
}