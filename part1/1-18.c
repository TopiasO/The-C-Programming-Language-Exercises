#include <stdio.h>
#define MAXLINE 1000        /* maximum input line size */

int getline(char line[], int maxline);
int remove_trailing(char line[], int size);

/* Write a program to remove trailing blanks and tabs 
from each line of input, and to delete entirely blank lines */

int main () {
    int len;                /* current line length */
    char line[MAXLINE];      /* current input line */

    while ((len = getline(line, MAXLINE)) > 0) 
        if (len > 0)
            /* print "check" to see if trailing tabs and blanks were
            removed*/
            printf("%s\"check\"", line);
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim) {
    int c, i, len;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    /* i-1 is the index of the last character in s */
    len = remove_trailing(s, i-1);
    if (len == 0) return 0;

    /*No \n at the end so that it is easier to see the program working
    if (c == '\n') {
        s[len] = '\n';
        ++len;
    }*/
    s[len] = '\0';
    return len;
}

/* remove_trailing: remove trailing blanks and tabs from s,
return new length of s */
int remove_trailing(char s[], int size) {
    while (size >= 0 && (s[size] == ' ' || s[size] == '\t')) {
        s[size] = '\0';
        --size;
    }
    return size+1;
}