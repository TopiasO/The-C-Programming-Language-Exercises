#include <stdio.h>

/* Write a program to count blanks, tabs, and newlines */

main () {
    int c, nl, t, b;

    nl = t = b = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') ++nl;
        else if (c == '\t') ++t;
        else if (c == ' ') ++b;
    }
    printf("b: %3d, t: %3d, nl: %3d\n", b, t, nl);
}