#include <stdio.h>
#include <string.h>

int main(){
    int t;
    scanf("%d", &t);

    char results[t][1005];
    for (int i = 0; i < t; i++)
    {
        char s[10005];
        unsigned int n;
        long long k;

        results[i][0] = '\0';

        scanf("%d %lld", &n, &k);
        scanf("%s", s);

        for (int j = 0; j < n; j++)
        {
            int ascii = ((unsigned int)s[j] + k - 97) % 26;

            char c[2] = {ascii + 97};
            strcat(results[i], c);
        }
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %s\n", i + 1, results[i]);
    }
    

    return 0;
}