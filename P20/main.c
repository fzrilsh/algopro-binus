#include <stdio.h>

long long gcd(long long a, long long b){
    while (b != 0)
    {
        long long c = b;
        b = a % b;
        a = c;
    }

    return a;
}

int main(){
    int T;
    scanf("%d", &T);

    long long result[T];

    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);

        long long res;
        long long current;

        if(N > 0){
            scanf("%lld", &res);
        }

        for (int j = 1; j < N; j++)
        {
            scanf("%lld", &current);

            res = gcd(res, current);
        }
        
        result[i] = res;
    }

    for (int i = 0; i < T; i++)
    {
        printf("Case #%d: %lld\n", i + 1, result[i]);
    }
    
    return 0;
}