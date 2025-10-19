#include <stdio.h>

int main(){
    long long n;

    scanf("%lld", &n);
    printf("%lld\n", (n * 100) + (25 * n * (n - 1)));

    return 0;
}