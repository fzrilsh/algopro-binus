#include <stdio.h>

int tillOne(long long n) {
    if(n == 1) return n;
    return n % 2 == 0 ? tillOne(n/2) : tillOne(n - 1) + tillOne(n + 1);
}

int main(){
    int t;
    scanf("%d", &t);

    long long results[t];
    for (int i = 0; i < t; i++)
    {
        long long n;
        scanf("%lld", &n);

        results[i] = tillOne(n);
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %lld\n", i + 1, results[i]);
    }
    
    

    return 0;
}