#include <stdio.h>
#include <string.h>

int main(){
    char result[1005];
    char s[1005];
    scanf("%s", s);

    int len = strlen(s);
    int counter = 0;

    for (int i = 0; i < len; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            result[counter] = s[i];
            counter++;
        }
    }
    
    if(counter == 0){
        return printf("Sandi Kosong!\n");
    }

    printf("%s\n", result);
    return 0;
}