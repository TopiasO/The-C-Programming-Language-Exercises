#include <stdio.h>
#define MAXLINE 1000        /* maximum input line size */
#define N 8                 /* Lets say that a tab stop appears every five columns */

int getline1(char line[], int maxline);
void copy(char to[], char from[]);
void detab(char line[], char temp[], int length);

/* Write a program detab that replaces tabs in the input with the
proper number of blanks to space the next tab stop. Assume a fixed set of
tab stops, every n columns. */

int main() {
    int len;                /* current line length */                    
    char line[MAXLINE];     /* current input line */
    char temp[MAXLINE];     /* temp store for line */

    while ((len = getline1(line, MAXLINE)) > 0) {
        copy(temp, line);
        detab(line, temp, len);
        printf("%s\n", line);
    }

    return 0;
}

/* getline: read a line into s */
int getline1(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}

/* detab: replace tabs in s with the proper amount of blank spaces */
void detab(char s[], char temp[], int length) {
    /* blanks used when calculating how many blanks till
    next tab stop. diff used to remember how many blanks have
    been used to replace tabs */
    int i, blanks, diff, j;

    for (i = diff = 0; i+diff < MAXLINE-1 && i < length; ++i) {
        if (temp[i] == '\t') {
            /* i+diff % N -> How many columns are used over the last tab stop
            Negate that from N and you get how many columns until next tab stop */
            blanks = N - ((i+diff) % N);

            /* Add corresponding amount of blanks to s */
            for (j = 0; j < blanks; ++j) {
                s[i+diff+j] = ' ';
            }

            /* Update the tab to blanks difference */
            diff += blanks-1;
        } else {
            s[i+diff] = temp[i];
        }
    }

    s[i+diff] = '\0';
}