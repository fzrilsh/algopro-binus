#include <stdio.h>

int f(int n, int *attempt){
    if(n == 0 || n == 1) {
        return n + 1;
    }

    if(n % 3 == 0){
        (*attempt)++;
    }
    
    if(n % 5 == 0){
        return n * 2;
    }

    return f(n - 1, attempt) + n + f(n - 2, attempt) + n - 2;
}

int main(){
    int t;
    scanf("%d", &t);

    int attemptResults[t];
    int results[t];

    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        int attempt = 0;
        int r = f(n, &attempt);

        attemptResults[i] = attempt;
        results[i] = r;
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %d %d\n", i + 1, results[i], attemptResults[i]);
    }

    return 0;
}