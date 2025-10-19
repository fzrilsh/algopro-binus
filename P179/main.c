#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    long long cashbacks[T];
    for (int i = 0; i < T; i++)
    {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        long long result = (a / 100) * b;
        cashbacks[i] = c >= result ? result : c;
    }
    
    for (int i = 0; i < T; i++)
    {
        printf("Case #%d: %lld\n", i + 1, cashbacks[i]);
    }
    
    return 0;
}