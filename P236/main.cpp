#include <stdio.h>

int main()
{
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL)
    {
        return printf("File not found.");
    }

    int t;
    fscanf(file, "%d\n", &t);

    int results[t];
    for (int i = 0; i < t; i++)
    {
        int n, a, b;
        fscanf(file, "%d %d %d\n", &n, &a, &b);

        char x[n+5];
        fscanf(file, "%s\n", x);

        results[i] = 0;
        int counter = 0;

        for (int j = 0; j < n; j++)
        {
            if (x[j] == '1')
            {
                counter++;
            }

            if(x[j] == '0' || j == n - 1) {
                if (counter >= a && counter <= b)
                {
                    results[i]++;
                }
                
                counter = 0;
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %d\n", i + 1, results[i]);
    }
    
    return 0;
}