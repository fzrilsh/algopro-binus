#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    long long req[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &req[i]);
    }
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int k = 0; k < n - i - 1; k++)
        {
            if (req[k] > req[k + 1])
            {
                long long temp = req[k];
                req[k] = req[k + 1];
                req[k + 1] = temp;
            }   
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if(req[i] != req[i + 1]){
            result++;
        }
    }

    printf("%d\n", result);
    return 0;
}