#include <stdio.h>
#include <stdbool.h>

int main(){
    unsigned int t;
    scanf("%d", &t);

    int results[t];
    for (int i = 0; i < t; i++)
    {
        unsigned int n;
        scanf("%d", &n);

        int a[n];
        results[i] = 0;

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }

        for (int j = 0; j < n; j++)
        {
            bool isFactor = false;
            for (int k = 0; k < n; k++)
            {
                if(isFactor) break;
                for (int l = 0; l < n; l++)
                {
                    if(k == l){
                        continue;
                    }

                    if(a[k] + a[l] == a[j]){
                        isFactor = true;
                        results[i] += 1;
                        break;
                    }
                }
            }
        }
        
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %d\n", i + 1, results[i]);
    }
    
    return 0;
}