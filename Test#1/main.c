#include <stdio.h>
#include <math.h>


int main() {
    char binary[65];
    long long decimal = 0;
    int i = 0;

    printf("Enter a binary number: ");
    scanf("%64s", binary);

    while (binary[i] != '\0') {
        decimal = decimal * 2 + (binary[i] - '0');
        i++;
    }

    printf("Decimal value: %lld\n", decimal);
    return 0;
}

