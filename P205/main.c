#include <stdio.h>

int main(){
    int x, y, k;
    int value = 0;

    scanf("%d %d %d", &x, &y, &k);
    while (1)
    {
        if(x == k && y == k){
            printf("%d\n", value);
            break;
        }

        if(value >= 100) {
            printf("-1\n");
            break;
        }

        x++;
        y--;
        value++;
    }

    return 0;
}