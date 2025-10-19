#include <stdio.h>
#include <string.h>

int main(){
    int t;
    scanf("%d", &t);
    
    char results[t][1005];
    for (int i = 0; i < t; i++)
    {
        int n;
        char s[1005];

        results[i][0] = '\0';

        scanf("%d", &n); getchar();
        scanf("%[^\n]", s);

        for (int j = 0; j < n; j++)
        {
            if (s[j] >= 'a' && s[j] <= 'z')
            {
                char c[2] = {s[j]};
                strcat(results[i], c);
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %s\n", i + 1, results[i]);
    }
    

    return 0;
}