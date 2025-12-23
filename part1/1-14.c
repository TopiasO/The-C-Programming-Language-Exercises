#include <stdio.h>

#define ASCII_LIMIT 256

/* Write a program to print a histogram of the frequencies of 
different characters in its input */
main () {
    int c, i1, i2;   /* store input and idx for loops */
    int char_counts[ASCII_LIMIT];

    /* Initialize frequency of every character to 0 */
    for (i1 = 0; i1<ASCII_LIMIT; ++i1) {
        char_counts[i1] = 0;
    }

    while ((c = getchar()) != EOF) {
        ++char_counts[c];
    }
    putchar('\n');
    for (i1=0; i1<ASCII_LIMIT; ++i1) {
        printf("Frequency of '\\%c':", (char) i1);
        for (i2=0; i2<char_counts[i1]; ++i2) printf("-");
        printf("\n");
    }   
}

