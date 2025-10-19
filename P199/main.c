#include <stdio.h>
#include <string.h>

int main(){
    int t;
    scanf("%d", &t);

    char results[t][1005];
    for (int i = 0; i < t; i++)
    {
        unsigned int q;
        char s[1005];
        scanf("%d %s", &q, s);

        for (int j = 0; j < q; j++)
        {
            int l, r;
            scanf("%d %d", &l, &r);

            l--;
            r--;

            char temp[1005];
            strcpy(temp, s);

            for (int a = l, b = r; a < b; a++, b--)
            {
                char temp = s[a];
                s[a] = s[b];
                s[b] = temp;
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