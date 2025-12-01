#include <stdio.h>

struct Subject
{
    char Code[13];
    char Name[105];
    int Credits;
};


int main(){
    int t;
    scanf("%d", &t);

    Subject subjects[1005];
    for (int i = 0; i < t; i++)
    {
        scanf("%s", subjects[i].Code); getchar();
        scanf("%[^\n]", subjects[i].Name); getchar();
        scanf("%d", &subjects[i].Credits);
    }
    
    int q;
    scanf("%d", &q);

    int orders[1005];
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &orders[i]);
    }
    
    for (int i = 0; i < q; i++)
    {
        Subject subject = subjects[orders[i] - 1];
        printf("Query #%d:\n", i + 1);
        printf("Code: %s\n", subject.Code);
        printf("Name: %s\n", subject.Name);
        printf("Credits: %d\n", subject.Credits);
    }
    
    return 0;
}