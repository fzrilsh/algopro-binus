#include <stdio.h>
#include <string.h>

void sort(char *s, int len){
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (s[j] > s[j + 1])
            {
                char temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

int main(){
    int r, c;
    scanf("%d %d", &r, &c);

    char rc[r][c + 1];
    for (int i = 0; i < r; i++)
    {
        char temp[c + 1];
        scanf("%s", temp);

        sort(temp, c);
        strcpy(rc[i], temp);
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r - 1; j++)
        {
            if (strcmp(rc[i], rc[j]) > 0)
            {
                char temp[c + 1];
                strcpy(temp, rc[j]);
                strcpy(rc[j], rc[i]);
                strcpy(rc[i], temp);
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        printf("%s\n", rc[i]);
    }

    return 0;
}