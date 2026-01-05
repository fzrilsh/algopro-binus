#include <stdio.h>
#include <string.h>

struct Dictionary
{
    char keyword[105];
    char word[105];
};


int main(){
    FILE *fp = fopen("testdata.in", "r");
    if(fp == NULL) {
        return printf("File not found.");
    }

    int t;
    fscanf(fp, "%d\n", &t);

    Dictionary dictionary[t];
    for (int i = 0; i < t; i++)
    {
        fscanf(fp, "%[^#]#%s\n", dictionary[i].keyword, dictionary[i].word);
    }

    int tc;
    fscanf(fp, "%d\n", &tc);

    char results[tc][10005];
    for (int i = 0; i < tc; i++)
    {
        results[i][0] = '\0';
        
        char x[10005];
        fscanf(fp, "%[^\n]\n", x);

        char *token = strtok(x, " ");
        while (token != NULL)
        {
            int flag = 0;
            for (int j = 0; j < t; j++)
            {
                if (strcmp(dictionary[j].keyword, token) == 0)
                {
                    flag = 1;
                    strcat(results[i], dictionary[j].word);
                    break;
                }
            }

            if (!flag)
            {
                strcat(results[i], token);
            }

            token = strtok(NULL, " ");
            if(token != NULL){
                strcat(results[i], " ");
            }
        }

        results[i][strlen(results[i])] = '\0';
    }

    for (int i = 0; i < tc; i++)
    {
        printf("Case #%d:\n%s\n", i + 1, results[i]);
    }

    return 0;
}