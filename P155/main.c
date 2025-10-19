#include <stdio.h>
#include <string.h>

int main(){
    int t;
    scanf("%d", &t);

    char results[t][1005];
    for (int i = 0; i < t; i++)
    {
        char s[1005];
        int m;

        scanf("%s", s); getchar();
        scanf("%d", &m); getchar();

        for (int j = 0; j < m; j++)
        {
            char a, b;
            scanf("%c %c", &a, &b); getchar();

            int len = strlen(s);
            for (int k = 0; k < len; k++)
            {
                if(s[k] == a){
                    s[k] = b;
                }
            }
        }

        strcpy(results[i], s);
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %s\n", i + 1, results[i]);
    }
    

    return 0;
}