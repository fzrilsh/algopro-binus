#include <stdio.h>
// Prob R - The Registration Begin
int main()
{
	char nim[11];
	char name[101];
	char classNum;
	int num;
	
	scanf("%10s", nim); getchar();
	scanf("%[^\n]", name); getchar();
	scanf("%c %d", &classNum, &num);
	
	printf("Id    : %s\n", nim);
	printf("Name  : %s\n", name);
	printf("Class : %c\n", classNum);
	printf("Num   : %d\n", num);
	return 0;
}