#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);

    int length[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &length[i]);
    }

    for (int i = 0; i < t; i++)
    {
        int sizeY = length[i];
        int sizeX = length[i] * 2 - 1;
        for (int y = 0; y < sizeY; y++)
        {
            for (int x = 0; x <= sizeX; x++)
            {
                int s = (sizeX / 2) - y;
                if(x < s){
                    printf(" ");
                    continue;
                }

                if(x < sizeX - s){
                    printf("*");
                }
            }

            printf("\n");
        }
    }

    return 0;
}