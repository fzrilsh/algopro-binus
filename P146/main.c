#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int valid = 0;

    for (int i = 0; i < n; i++)
    {
        int seen[n + 1];
        for (int j = 0; j <= n; j++)
        {
            seen[j] = 0;
        }

        for (int j = 0; j < n; j++)
        {
            int number = matrix[i][j];
            if(seen[number]){
                valid = 1;
                break;
            }

            seen[number] = 1;
        }

        if(valid){
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int seen[n + 1];
        for (int j = 0; j <= n; j++)
        {
            seen[j] = 0;
        }

        for (int j = 0; j < n; j++)
        {
            int number = matrix[j][i];
            if(seen[number]){
                valid = 1;
                break;
            }

            seen[number] = 1;
        }

        if(valid){
            break;
        }
    }

    if(valid){
        printf("Nay\n");
    } else {
        printf("Yay\n");
    }

    return 0;
}