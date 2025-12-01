#include <stdio.h>

int main(){
    unsigned int n;
    scanf("%d", &n);

    unsigned int xi[105] = {0};
    for (int i = 0; i < n; i++)
    {
        unsigned int x;
        scanf("%d", &x);

        xi[x + '0']++;
    }

    for (int i = 0; i < n; i++)
    {
        if(xi[i + '0'] % 2 != 0){
            printf("%d\n", i);
            break;
        }
    }
    
    return 0;
}