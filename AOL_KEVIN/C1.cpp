#include <stdio.h>
#include <string.h>
#include <ctype.h>

void invertCase(char s[]) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {
        if(islower(s[i]))
            s[i] = toupper(s[i]);
        else if(isupper(s[i]))
            s[i] = tolower(s[i]);
    }
}

int main() {
    char a[105], b[105];
    char prefix[105] = "";
    char suffix[105] = "";
    char result[210] = "";
    int i, la, lb;

    scanf("%s", a);
    scanf("%s", b);

    i = 0;
    while(a[i] && b[i] && a[i] == b[i]) {
        prefix[i] = a[i];
        i++;
    }
    prefix[i] = '\0';

    la = strlen(a) - 1;
    lb = strlen(b) - 1;
    i = 0;
    while(la >= 0 && lb >= 0 && a[la] == b[lb]) {
        suffix[i++] = a[la--];
        lb--;
    }
    suffix[i] = '\0';

    for(i = 0; i < strlen(suffix)/2; i++) {
        char temp = suffix[i];
        suffix[i] = suffix[strlen(suffix)-1-i];
        suffix[strlen(suffix)-1-i] = temp;
    }

    if(strlen(prefix) == 0 && strlen(suffix) == 0) {
        printf("No Output\n");
        return 0;
    }

    strcpy(result, prefix);
    strcat(result, suffix);
    invertCase(result);

    printf("%s\n", result);
    return 0;
}