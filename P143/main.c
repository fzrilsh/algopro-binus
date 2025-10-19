#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    unsigned long t;
    scanf("%ld", &t);

    bool results[t];
    for (int i = 0; i < t; i++)
    {
        char s[505];

        getchar();
        scanf("%[^\n]", s);

        bool flag = true;
        int len = strlen(s);

        for (int j = 0; j < len; j++)
        {
            if (s[j] != s[len - j - 1])
            {
                flag = false;
                break;
            }

        }

        results[i] = flag;
    }

    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: %s\n", i + 1, results[i] ? "Yay, it's a palindrome" : "Nah, it's not a palindrome");
    }
    
    return 0;
}