#include <stdio.h>
#include <string.h>

int main(){
    int t;
    scanf("%d", &t);

    char results[t][1005];
    for (int i = 0; i < t; i++)
    {
        char s[1005];
        scanf("%s", s);

        results[i][0] = '\0';

        int len = strlen(s);
        for (int j = len; j >= 0; j--)
        {
            char c[2] = {s[j]};
            // printf("%c", s[j]);
            strcat(results[i], c);
        }
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d : %s\n", i + 1, results[i]);
    }
    
    
    return 0;
}