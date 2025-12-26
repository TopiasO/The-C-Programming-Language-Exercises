#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char s[]);

/* Write a function reverse(s) that reverses the character
string s. Use it to write a program that reverses its input a line at a time. */

int main() {
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    len = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("Reversed: %s\n", line);
    }

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

/* reverse: reverses the character string s */
void reverse(char s[]) {
    int c;         /* temporary storage for a char */
    int i, end;       /* s.end() */

    for (end = 0; s[end+1] != '\0'; ++end);
    for (i = 0; i < end; ++i, --end) {
        c = s[i];
        s[i] = s[end];
        s[end] = c;
    }
}