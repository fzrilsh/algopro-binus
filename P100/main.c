#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);

    int books[t];
    for (int i = 0; i < t; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        int front = b / 2;
        int back = a / 2 - front;
        books[i] = front < back ? front : back;
    }

    for (int i = 0; i < t; i++)
    {
        int front = books[i] / 2;
        printf("Case #%d: %d\n", i + 1, books[i]);
    }

    return 0;
}