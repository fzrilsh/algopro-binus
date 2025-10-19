#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long getMinGap(long long *numbers, int len){
    long long result = LLONG_MAX;
    for (int i = 0; i < len - 1; i++)
    {
        long long gap = llabs(numbers[i] - numbers[i + 1]);
        if(gap < result) {
            result = gap;
        }
    }
    
    return result;
}

int main(){
    int t;
    scanf("%d", &t);

    long long result[t];
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        long long x[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &x[i]);
        }
        
        long long gap = getMinGap(x, n);
        result[i] = gap;
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %lld\n", i + 1, result[i]);
    }
    

    return 0;
}