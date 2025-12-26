#include <stdio.h>
#define MAXLINE 1000        /* maximum input line size */
#define MINLINE 80          /* minimum input line size to be printed*/

int getline(char line[], int maxline);

/* Write a program to print all input lines that are longer than 80 
characters. */

int main () {
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    len = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len >= MINLINE) 
            printf("%s\n", line);

    return 0;
}


/* getline: read a line into s, return length */
int getline(char s[], int lim) {
    int c, i;

    for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i)
        if (i < lim -1)
            s[i] = c;

    if (c == '\n' && i <= lim - 1) {
        s[i] = c;
        ++i;
        s[i] = '\0';
    } else {
        s[lim] = '\0';
    }
    return i;
}