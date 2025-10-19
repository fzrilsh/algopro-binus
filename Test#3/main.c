#include <stdio.h>

int f(int n){
    if(n == 0 || n == 1) {
        return n;
    }

    return f(n-2) + f(n-1);
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%d\n", f(n - 1 + 3) - 1);
    return 0;
}