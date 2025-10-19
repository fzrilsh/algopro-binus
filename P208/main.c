#include <stdio.h>
#include <stdlib.h>

int main(){
    int t;
    scanf("%d", &t);

    int **output[t];
    int outputSize[t];
    for (int i = 0; i < t; i++)
    {
        int matrixSize;
        scanf("%d", &matrixSize);

        int matrixs[3][matrixSize][matrixSize];
        for (int j = 0; j < 3; j++)
        {
            for (int row = 0; row < matrixSize; row++)
            {
                for (int col = 0; col < matrixSize; col++)
                {
                    scanf("%d", &matrixs[j][row][col]);
                }
            }

            if(i != t - 1 || j != 2) scanf("");
        }

        int results[matrixSize][matrixSize];
        for (int row = 0; row < matrixSize; row++)
        {
            for (int col = 0; col < matrixSize; col++)
            {
                results[row][col] = 0;
                for (int k = 0; k < matrixSize; k++)
                {
                    results[row][col] += matrixs[0][row][k] * matrixs[1][k][col];
                }
            }
        }

        int **finalResult = (int **)malloc(matrixSize * sizeof(int *));
        for (int row = 0; row < matrixSize; row++)
        {
            finalResult[row] = (int *)malloc(matrixSize * sizeof(int));
        }
        
        for (int row = 0; row < matrixSize; row++)
        {
            for (int col = 0; col < matrixSize; col++)
            {
                finalResult[row][col] = 0;
                for (int k = 0; k < matrixSize; k++)
                {
                    finalResult[row][col] += results[row][k] * matrixs[2][k][col];
                }
            }
        }

        output[i] = finalResult;
        outputSize[i] = matrixSize;
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d:\n", i + 1);
        for (int row = 0; row < outputSize[i]; row++)
        {
            for (int col = 0; col < outputSize[i]; col++)
            {
                if(col == outputSize[i] - 1){
                    printf("%d", output[i][row][col]);
                } else {
                    printf("%d ", output[i][row][col]);
                }
            }
            
            printf("\n");
        }
        
    }

    return 0;
}