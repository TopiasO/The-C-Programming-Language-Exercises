#include <stdio.h>

#define IN 1    /* inside a word */
#define OUT 0   /* outside a word */
#define MAXWORDAMOUNT 1000

/* Write a program to print a histogram of the lengths
of words in its input. */
main () {
    int c, for_idx, while_idx, state, len;
    int wordlengths[MAXWORDAMOUNT];

    for (for_idx = 0; for_idx < MAXWORDAMOUNT; ++for_idx) {
        wordlengths[for_idx] = 0;
    }

    state = OUT;
    while_idx = 0;
    while ((c = getchar()) != EOF) {
        if ((c == ' ' || c == '\n' || c == '\t')) {
            if (state == IN) {
                wordlengths[while_idx] = len;
                len = 0;
                ++while_idx;
            }
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
        }
        if (state == IN) ++len;
    }
    while_idx = 0;
    while (wordlengths[while_idx] != 0) {
        printf("%d. word:", while_idx+1);
        for (for_idx=0; for_idx<wordlengths[while_idx]; ++for_idx) printf("-");
        printf("\n");
        ++while_idx;
    }
}