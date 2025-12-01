#include <stdio.h>

struct Student
{
    char ID[15];
    char Name[20];
    int Grade;
};

double Mean(Student data[], long long counter){
    int total = 0;
    for (long long i = 0; i < counter; i++)
    {
        total += data[i].Grade;
    }
    
    return (double)total / counter;
}

int main(){
    long long t;
    scanf("%lld", &t);

    Student students[t];
    for (long long i = 0; i < t; i++)
    {
        scanf("%s", students[i].ID); getchar();
        scanf("%[^\n]", students[i].Name); getchar();
        scanf("%d", &students[i].Grade);
    }

    double mean = Mean(students, t);
    Student orders[t];

    long long counter = 0;
    for (long long i = 0; i < t; i++)
    {
        if((double)students[i].Grade >= mean){
            orders[counter] = students[i];
            counter++;
        }
    }

    for (long long i = 0; i < counter; i++)
    {
        printf("%s %s\n", orders[i].ID, orders[i].Name);
    }

    return 0;
}