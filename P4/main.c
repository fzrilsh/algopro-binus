#include <stdio.h>

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = n; i < n+m; i++)
    {
        printf("%d\n", i);
    }

    int temperature = 50;
    switch (temperature)
    {
    case 50:
        /* code */
        break;
    
    default:
        break;
    }

    return 0;
}