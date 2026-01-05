#include <stdio.h>

// void sort(int *data, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (data[j] > data[j + 1])
//             {
//                 int temp = data[j];
//                 data[j] = data[j + 1];
//                 data[j + 1] = temp;
//             }
//         }
//     }
// }

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *data, int low, int high)
{
    int i = low - 1;
    int pivot = data[high];

    for (int j = low; j <= high - 1; j++)
    {
        if (data[j] < pivot)
        {
            i++;
            swap(&data[i], &data[j]);
        }
    }

    swap(&data[i + 1], &data[high]);
    return i + 1;
}

void sort(int *data, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(data, low, high);

        sort(data, low, partitionIndex - 1);
        sort(data, partitionIndex + 1, high);
    }
}

int main()
{
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL)
    {
        return printf("File not found\n");
    }

    int t;
    fscanf(file, "%d\n", &t);

    int results[t];
    for (int i = 0; i < t; i++)
    {
        int n, m;
        fscanf(file, "%d %d\n", &n, &m);

        int data[n * m];
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                fscanf(file, "%d", &data[k + (j * m)]);
            }
        }

        sort(data, 0, n * m - 1);

        int mid = (n * m - 1) / 2;
        results[i] = data[mid];
    }
    fclose(file);

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %d\n", i + 1, results[i]);
    }

    return 0;
}