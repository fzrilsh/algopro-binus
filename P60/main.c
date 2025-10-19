#include <stdio.h>

int main(){
    int a, b;

    scanf("%d %d", &a, &b);
    float result = (float)(a - b) / a * 100;

    printf("%.2f%%\n", result);
    return 0;
}