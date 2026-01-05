#include <stdio.h>
#include <string.h>

void fibo(char fib[20][10005], int n, int counter){
    if(counter > n){
        return;
    }

    strcpy(fib[counter], fib[counter-1]);
    strcat(fib[counter], fib[counter-2]);
    
    fibo(fib, n, counter + 1);
}

int main() {
    int t;
    scanf("%d", &t);

    char results[t][10005];
    for (int i = 0; i < t; i++)
    {
        int n;
        char s0[10005], s1[10005];
        char fib[20][10005];

        scanf("%d %s %s", &n, s0, s1);

        strcpy(fib[0], s0);
        strcpy(fib[1], s1);

        fibo(fib, n, 2);
        strcpy(results[i], fib[n]);
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %s\n", i + 1, results[i]);
    }
    
    return 0;
}