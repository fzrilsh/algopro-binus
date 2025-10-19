#include <stdio.h>

int main(){
    
    double total = 0;
    int min = 1e9;
    int max = 0;

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);

        total += a;
        total += i - 1;

        min = min + 1 < a ? min + 1 : a;
        max = max + 1 > a ? max + 1 : a;

        double avg = total / i;

        printf("%d %d %.4f\n", min, max, avg);
    }
    

    return 0;
}