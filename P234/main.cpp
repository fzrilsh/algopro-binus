#include <stdio.h>
#include <string.h>

struct Result
{
    char alphabet;
    int count;
};

struct Output
{
    Result *results;
    int size;
};

int search(char x[105], char q)
{
    int count = 0;
    int len = strlen(x);

    for (int i = 0; i < len; i++)
    {
        if (x[i] == q)
        {
            count++;
        }
    }
    return count;
}

FILE *fp;

int main()
{
    fp = fopen("testdata.in", "r");
    if (fp == NULL)
    {
        printf("File not found.\n");
        return 1;
    }

    int t;
    fscanf(fp, "%d", &t);

    Output *output = new Output[t];

    for (int i = 0; i < t; i++)
    {
        char x[105];
        fscanf(fp, "%s", x);

        int n;
        fscanf(fp, "%d", &n);

        int isChanged[105] = {0};
        for (int j = 0; j < n; j++)
        {
            char a, b;
            fscanf(fp, " %c %c", &a, &b);

            if (isChanged[a - 'A'] == 0)
            {
                int len = strlen(x);
                for (int k = 0; k < len; k++)
                {
                    if (x[k] == a)
                    {
                        x[k] = b;
                    }
                }
                isChanged[a - 'A'] = 1;
            }
        }

        output[i].results = new Result[26];
        int countIndex = 0;

        for (char c = 'A'; c <= 'Z'; c++)
        {
            int count = search(x, c);

            if (count > 0)
            {
                output[i].results[countIndex].alphabet = c;
                output[i].results[countIndex].count = count;
                countIndex++;
            }
        }
        output[i].size = countIndex;
    }

    for (int i = 0; i < t; i++)
    {
        int len = output[i].size;
        for (int j = 0; j < len; j++)
        {
            printf("%c %d\n", output[i].results[j].alphabet, output[i].results[j].count);
        }
    }

    fclose(fp);
    return 0;
}