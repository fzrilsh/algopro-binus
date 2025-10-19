#include <stdio.h>

int main(){
    int n[9];

    for (int i = 0; i < 9; i += 3)
    {
        int n1, n2;
        scanf("%d + %d =", &n1, &n2);

        n[i] = n1;
        n[i + 1] = n2;
        n[i + 2] = n1 + n2;
    }

    for (int i = 2; i < 9; i += 3)
    {
        printf("%d\n", n[i]);
    }
    

    return 0;
}