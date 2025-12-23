#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */

/* Write a program to copy its input to its output,
    replacing each string of one or more blanks by a single blank. */

main () {
    int c, state;

    state = IN;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            state = OUT;
            continue;
        } else if (state == OUT) {
            state = IN;
            putchar(' ');
        }
        putchar(c);
    }
}