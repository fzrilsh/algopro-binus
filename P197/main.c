#include <stdio.h>

int main(){
    unsigned int t;
    scanf("%d", &t);

    long long result[t];
    for (int i = 0; i < t; i++)
    {
        unsigned int n, m;
        scanf("%d %d", &n, &m);

        long long total = 0;
        for (int a = 0; a < n; a++)
        {
            long long ai = 0;
            for (int b = 0; b < m; b++)
            {
                long long m;
                scanf("%lld", &m);

                if (m > ai){
                    ai = m;
                }
            }

            total += ai;
        }

        result[i] = total;
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %lld\n", i + 1, result[i]);
    }
    

    return 0;
}