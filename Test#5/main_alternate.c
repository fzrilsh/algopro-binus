#include <stdio.h>
#include <string.h>

int main(){
    char s[10000];
    int m, x;

    scanf("%[^\n]", s); getchar();
    scanf("%d %d", &m, &x);

    char words[1000];
    int len = strlen(s);
    int counter = 0;

    for (int i = 0; i < len; i++)
    {
        if(s[i] == 32 || (m == 0 && i == 0)){
            printf("%d\n", counter);
            if(counter == m){
                int j = 0;
                while ((s[i] != '\0') || (s[i] != 32))
                {
                    words[j] = s[i];
                    j++, i++;
                }
                break;
            }

            counter++;
        }
    }
    

    for (int i = 0; i < x; i++)
    {
        printf("%s", words);
        printf(i < x-1 ? " " : "\n");
    }
    

    return 0;
}