#include <stdio.h>

int main(){
    long long n;
    scanf("%lld", &n);

    long long a[n];
    long long b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &b[i]);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[b[i]]);
    }
    
    for (int i = 0; i < n; i++)
    {
        if(i == n - 1){
            printf("%lld", a[i]);
        } else {
            printf("%lld ", a[i]);
        }
    }
    
    printf("\n");

    return 0;
}