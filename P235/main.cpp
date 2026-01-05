#include <stdio.h>
#include <math.h>

struct Output
{
    int perimeter;
    int area;
};


int main(){
    FILE *file = fopen("testdata.in", "r");
    if(file == NULL) {
        return printf("File not found.");
    }

    int t;
    fscanf(file, "%d\n", &t);

    Output outputs[t];
    for (int i = 0; i < t; i++)
    {
        int n;
        fscanf(file, "%d\n", &n);

        outputs[i].area = 0;
        outputs[i].perimeter = (n * 2) * 2;

        int x[n];
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%d", &x[j]);
            outputs[i].area += x[j] * 4;
        }

        outputs[i].perimeter += x[0] * 2;
        outputs[i].perimeter += x[n-1] * 2;

        for (int j = 0; j < n - 1; j++)
        {
            outputs[i].perimeter += abs(x[j] - x[j+1]) * 2;
        }
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %d %d\n", i + 1, outputs[i].perimeter, outputs[i].area);
    }
    

    return 0;
}