#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/* Write a program to copy its input to its output,
    replacing each tab by \t, each backspace by \b, and each backslash by \\.
    This makes tabs and backspaces visible in an unambiguous way. */

main () {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\b') {
            putchar('\\');
            putchar('b');
        } else if (c == '\t') {
            putchar('\\');
            putchar('t');
        } else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        } else {
            putchar(c);
        }
    }
}