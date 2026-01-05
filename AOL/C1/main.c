#include <stdio.h>
#include <string.h>

int main()
{
    char a[105];
    char b[105];

    // printf("%d", 'a' - 'A'); 32

    scanf("%s", a);
    scanf("%s", b);

    int aLen = strlen(a);
    int bLen = strlen(b);
    int len = aLen > bLen ? bLen : aLen;

    char prefix[105];
    char suffix[105];

    int prefixCounter = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] != b[i])
            break;

        prefix[prefixCounter] = a[i] >= 'a' ? a[i] - 32 : a[i] + 32;
        prefixCounter++;
    }

    int suffixCounter = 0;
    int indexA = aLen - 1;
    int indexB = bLen - 1;

    while (indexA >= 0 && indexB >= 0)
    {
        if (a[indexA] != b[indexB])
            break;

        suffix[suffixCounter] = (a[indexA] >= 'a') ? a[indexA] - 32 : a[indexA] + 32;
        suffixCounter++;

        indexA--;
        indexB--;
    }

    if (!prefixCounter && !suffixCounter)
    {
        printf("No Output\n");
        return 0;
    }

    for (int i = 0; i < prefixCounter; i++)
    {
        printf("%c", prefix[i]);
    }

    for (int i = suffixCounter - 1; i >= 0; i--)
    {
        printf("%c", suffix[i]);
    }

    printf("\n");
    return 0;
}