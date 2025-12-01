#include <stdio.h>

int main(){
    int dimension;
    scanf("%d", &dimension);

    int matrix[dimension][dimension];
    for (int row = 0; row < dimension; row++)
    {
        for (int col = 0; col < dimension; col++)
        {
            scanf("%d", &matrix[row][col]);
        }
    }

    int swapCount;
    scanf("%d", &swapCount);

    for (int i = 0; i < swapCount; i++)
    {
        int target;
        scanf("%d", &target);
        target -= 1;

        for (int row = 0; row < dimension; row++)
        {
            if(row != target) {
                int temp = matrix[target][row];
                matrix[target][row] = matrix[row][target];
                matrix[row][target] = temp;
            }
        }
    }

    for (int row = 0; row < dimension; row++)
    {
        for (int col = 0; col < dimension; col++)
        {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}