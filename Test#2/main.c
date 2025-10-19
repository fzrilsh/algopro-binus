#include <stdio.h>

int main(){
    int d = 2;

    switch (d)
    {
    case 2:
        printf("2\n");
    case 3:
        printf("3\n");
        break;
    case 4: 
        printf("4\n");
        break;
    default:
        break;
    }
}