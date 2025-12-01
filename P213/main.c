#include <stdio.h>

char fiboString(char n){
    if(n == 1 || n == 2){
        return n;
    }

    return fiboString(n - 1) + fiboString(n - 2);
}

int main(){
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        
    }
    

    return 0;
}