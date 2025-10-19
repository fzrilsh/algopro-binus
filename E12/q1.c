#include <stdio.h>
#include <limits.h>

int main(){
    int n[10];
    int max = 0;
    int min = INT_MAX;
    double avg = 0;


    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &n[i]);
        if (max < n[i]) {
            max = n[i];
        }

        if (min > n[i]) {
            min = n[i];
        }
    }

    for (int i = 0; i < 10; i++)
    {
        avg += n[i];
    }
    
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    printf("Average: %.2f\n", avg / 10);

    return 0;
}