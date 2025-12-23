#include <stdio.h>

/* Verify that the expression getchar() != EOF 
    is 0 or 1*/

main () {
    int i, c;

    c = getchar();
    i = c != EOF;
    printf("%d", i);
}