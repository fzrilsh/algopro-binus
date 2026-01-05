#include <stdio.h>

void sort(long long *x, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if(x[j] > x[j+1]) {
                long long temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    long long x[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &x[i]);
    }
    sort(x, n);

    long long y;
    scanf("%lld", &y);

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (y >= x[i])
        {
            y -= x[i];
            total++;
        }
    }

    printf("%d\n", total);
    return 0;
}