#include <stdio.h>
#include <string.h>

int main() {
    char text[256];
    char *words[50];
    int counter = 0;

    scanf("%[^\n]", text);

    char *token = strtok(text, " ");
    while (token != NULL)
    {
        words[counter] = token;
        counter++;
        token = strtok(NULL, " ");
    }

    
    for (int i = counter - 1; i >= 0; i--)
    {
        if(words[i] == NULL) continue;
        printf("%s", words[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    
    printf("\n");

    return 0;
}