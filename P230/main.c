#include <stdio.h>
#include <stdbool.h>

void dfs(int n, int m, char house[n][m], int row, int col, int *count, bool visitedIndex[n][m]){
    if(row >= n || row < 0) return;
    if(col >= m || col < 0) return;
    if(visitedIndex[row][col]) return;
    if(house[row][col] == '#') return;
    // printf("%c %d %d\n", house[row][col], row, col);
    
    visitedIndex[row][col] = true;
    if(house[row][col] == '.'){
        (*count)++;
    }

    dfs(n, m, house, row + 1, col, count, visitedIndex);
    dfs(n, m, house, row - 1, col, count, visitedIndex);
    dfs(n, m, house, row, col + 1, count, visitedIndex);
    dfs(n, m, house, row, col - 1, count, visitedIndex);
}

int main(){
    int t;
    scanf("%d", &t);

    int results[t];
    for (int i = 0; i < t; i++)
    {
        unsigned int n, m;
        scanf("%d %d", &n, &m); getchar();

        int startRow = -1;
        int startCol = -1;

        int count = 0;
        char house[n][m];
        bool visitedIndex[n][m];

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                scanf(" %c", &house[row][col]);
                visitedIndex[row][col] = false;

                if(house[row][col] == 'S'){
                    startRow = row;
                    startCol = col;
                }
            }
        }

        dfs(n, m, house, startRow, startCol, &count, visitedIndex);        
        results[i] = count;
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %d\n", i + 1, results[i]);
    }

    return 0;
}