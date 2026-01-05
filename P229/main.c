#include <stdio.h>

int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int best;

void solveRec(int x, int y, int tx, int ty, int step) {
    if (step >= best) {
        return;
    }

    if (x == tx && y == ty) {
        best = step;
        return;
    }

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
            solveRec(nx, ny, tx, ty, step + 1);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    int results[t];
    for (int i = 0; i < t; i++) {
        char s1[3], s2[3];
        scanf("%s %s", s1, s2);

        int x1 = s1[0] - 'A' + 1;
        int y1 = s1[1] - '0';

        int x2 = s2[0] - 'A' + 1;
        int y2 = s2[1] - '0';

        best = 7;
        solveRec(x1, y1, x2, y2, 0);

        results[i] = best;
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %d\n", i + 1, results[i]);
    }

    return 0;
}