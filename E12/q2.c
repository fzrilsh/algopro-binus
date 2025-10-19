#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char password[100];
    char special[] = "_/@-!?*#";

    int uppercase = 0;
    int lowercase = 0;
    int specialchar = 0;
    int inclnum = 0;

    scanf("%[^\n]", password);

    int len = strlen(password);
    if(len > 12){
        printf("Password must be less than 12 characters.\n");
        return 0;
    }

    if(len <= 0){
        printf("Password must be at least 1 characters.\n");
        return 0;
    }

    char *ptr = password;
    while (*ptr != '\0')
    {
        if(isspace((unsigned int)*ptr)){
            printf("Whitespace is not allowed in password.\n");
            return 0;
        }

        if(isupper((unsigned int)*ptr)){
            uppercase = 1;
        }

        if(islower((unsigned int)*ptr)){
            lowercase = 1;
        }

        if(isnumber((unsigned int)*ptr)) {
            inclnum = 1;
        }

        if(strchr(special, (unsigned int)*ptr) != NULL){
            specialchar = 1;
        }

        ptr++;
    }
    
    if (!uppercase){
        printf("At least 1 upper case character in the password.\n");
        return 0;
    }

    if (!lowercase){
        printf("At least 1 lower case character in the password.\n");
        return 0;
    }

    if (!specialchar){
        printf("At least 1 special character in the password.\n");
        return 0;
    }

    if (!inclnum){
        printf("At least 1 number in the password.\n");
        return 0;
    }

    printf("Password validated successfully.\n");
    return 1;
}