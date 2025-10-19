#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char encryptChar(char c) {
    if(c >= 'A' && c <= 'D') return 'A';
    else if(c >= 'E' && c <= 'H') return 'E';
    else if(c >= 'I' && c <= 'N') return 'I';
    else if(c >= 'O' && c <= 'T') return 'O';
    else if(c >= 'U' && c <= 'Z') return 'U';
    else return c;
}

int main(){
    int t;
    scanf("%d", &t);

    char vocalResult[t][1005];
    char distanceResult[t][1005];

    for (int i = 0; i < t; i++)
    {
        char s[1005];
        scanf("%s", s);

        vocalResult[i][0] = '\0';
        distanceResult[i][0] = '\0';

        int sLen = strlen(s);
        for (int j = 0; j < sLen; j++)
        {
            if(s[j] == '\0') break;

            char selected_vocal[2] = {encryptChar(s[j])};
            char distance[2] = {abs(selected_vocal[0] - s[j]) + '0'};

            strcat(vocalResult[i], selected_vocal);
            strcat(distanceResult[i], distance);
        }
    }
    
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d:\n%s\n%s\n", i + 1, vocalResult[i], distanceResult[i]);
    }

    return 0;
}