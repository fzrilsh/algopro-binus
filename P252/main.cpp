#include <stdio.h>

void sort(int *xi, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (xi[j] > xi[j + 1])
            {
                int temp = xi[j];
                xi[j] = xi[j + 1];
                xi[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    int minResults[t];
    int maxResults[t];

    for (int i = 0; i < t; i++)
    {
        int n, x;
        scanf("%d %d", &n, &x);

        int xi[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &xi[j]);
        }

        sort(xi, n);

        int min = 0;
        int max = 0;

        int k = 0;
        while (k < n && max + xi[k] <= x)
        {
            max += xi[k];
            k++;
        }
        max = k;

        k = n - 1;
        while (k >= 0 && min + xi[k] <= x)
        {
            min += xi[k];
            k--;
        }
        min = n - 1 - k;

        minResults[i] = min;
        maxResults[i] = max;
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %d %d\n", i + 1, minResults[i], maxResults[i]);
    }

    return 0;
}