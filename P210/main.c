#include <stdio.h>

int sum(int n){
    if(!n) return 0;

    int a;
    scanf("%d", &a);

    return a + sum(n - 1);
}

int main(){
    int t;
    scanf("%d", &t);

    int results[t];
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);

        results[i] = sum(n);
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %d\n", i + 1, results[i]);
    }

    return 0;
}