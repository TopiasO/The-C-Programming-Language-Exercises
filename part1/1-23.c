#include <stdio.h>
#define IN_BLOCK_COMMENT 0
#define IN_LINE_COMMENT 1
#define OUT_OF_COMMENT 2

/* Write a program to remove all comments from a C program.
Don't forget to handle quoted strings and character constants properly.
C comments do not nest */
 
int main() {
    /* Iterate through the file by keeping track of 2 consecutive characters.
    The program only prints when putchar_cd == 0. This makes it easier 
    to move past comment denoting characters */
    int c1, c2, putchar_cd, state;
    
    putchar_cd = 0;
    state = OUT_OF_COMMENT;
    /* Initialize as empty chars */
    c1 = c2 = '\0';

    while (c1 != EOF) {
        /* If a line comment ends wait for c1 == '\n' before printing c1.
        If a block comment ends wait for c1 to be what comes after '/' before
        printing */
        if (c1 == '/' && c2 == '/') state = IN_LINE_COMMENT;
        else if (c2 == '\n' && state == IN_LINE_COMMENT) {
            state = OUT_OF_COMMENT;
            putchar_cd = 1;
        } else if (c1 == '/' && c2 == '*') state = IN_BLOCK_COMMENT;
        else if (c1 == '*' && c2 == '/') {
            state = OUT_OF_COMMENT;
            putchar_cd = 2;
        }

        if (c1 != '\0' && state == OUT_OF_COMMENT && putchar_cd == 0) {
            putchar(c1);
        }

        c1 = c2;
        if (putchar_cd > 0) --putchar_cd;

        /* Iterate through the file */
        c2 = getchar();
    }

    return 0;
}



