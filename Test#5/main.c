#include <stdio.h>
#include <string.h>

int main(){
    char s[10000];
    int m, x;

    scanf("%[^\n]", s); getchar();
    scanf("%d %d", &m, &x);

    char *token = strtok(s, " ");
    int counter = 0;

    char words[10000];
    while (token != NULL)
    {
        if(counter == m){
            strcpy(words, token);
        }

        counter++;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < x; i++)
    {
        printf("%s", words);
        printf(i < x-1 ? " " : "\n");
    }
    

    return 0;
}