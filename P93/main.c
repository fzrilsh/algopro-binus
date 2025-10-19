#include <stdio.h>

int exchange(int a, int b, int value){
    if(a < b) return value;

    int fresh = a / b;
    int empty = (a % b) + fresh;

    return exchange(empty, b, value + fresh);
}

int main(){
    int t;

    scanf("%d", &t);
    int result[t];

    for (int i = 0; i < t; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        result[i] = exchange(a, b, a);
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %d\n", i + 1, result[i]);
    }
    

    return 0;
}