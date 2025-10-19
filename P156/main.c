#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int main(){
    int t;
    scanf("%d", &t);

    int result[t];
    for (int i = 0; i < t; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        
        char x[1000000];
        char y[1000000];

        int x_length = snprintf(x, sizeof(x), "%d", a);
        int y_length = snprintf(y, sizeof(y), "%d", b);

        int length = x_length > y_length ? x_length : y_length;
        snprintf(x, sizeof(x), "%0*d", length, a);
        snprintf(y, sizeof(y), "%0*d", length, b);

        char total[length];
        for (int j = 0; j < length; j++)
        {
            char c[1000];
            snprintf(c, sizeof(c), "%d", (x[j] - '0') + (y[j] - '0'));
            total[j] = c[strlen(c) - 1];
        }


        result[i] = atoi(total);
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %d\n", i + 1, result[i]);
    }
    
    return 0;
}