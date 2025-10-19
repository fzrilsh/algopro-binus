#include <stdio.h>

int main() {
    int t, a, b, c, d, e, f, i = 0;
    for (scanf("%d", &t); i++ < t; putchar('\n')) {
        scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
        printf("Case #%d: ", i);
        while (a--) putchar('a');
        while (b--) putchar('s');
        while (c--) putchar('h');
        while (d--) putchar('i');
        while (e--) putchar('a');
        while (f--) putchar('p');
    }
}