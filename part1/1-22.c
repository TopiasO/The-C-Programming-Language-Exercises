#include <stdio.h>
#define MAXLINE 1000        /* input line maximum length */
#define COLUMN_STOP 9       /* n-th column, before which input is folded */
#define TAB_WIDTH 8         /* tab is 8 columns wide */

int getline1(char line[], int maxline);
void fold(char line[], int length, int start, int column_stop);
void copy_range(char to[], char from[], int start, int end);

/* Write a program to "fold" long input lines into two or more
shorter lines after the last non-blank character that occurs before the n-th
column on input. Make sure your program does something intelligent with very
long lines, and if there are no blanks or tabs before the specified column,*/

int main() {
    int c, len;
    char line[MAXLINE];

    /* Do tabs count as blanks? */

    while ((len = getline1(line, MAXLINE)) > 0) {
        fold(line, len, 0, COLUMN_STOP);
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

/* fold: folds a string into 2 or more strings less than 'COLUMN_STOP' 
in length. Folds from last blank before 'COLUMN_STOP' or from
'COLUMN_STOP' if there are no blanks. */
void fold(char s[], int len, int start, int col_stop) {
    int i, last_non_blank, end_of_line;
    char temp[col_stop];      /* buffer for the substring before fold point */

    last_non_blank = start + col_stop;
    end_of_line = 1;
    for (i = 0; i <= col_stop && i+start <= len; ++i) {
        if (s[i+start] == '\0' || s[i+start] == '\n') {
            end_of_line = 0;
        } else if (s[i+start] == ' ') {
            last_non_blank = i+start;
        }
    }
    if (last_non_blank-start != 0) {
        /* If blank was found, fold there. Otherwise fold at 'COLUMN_STOP' */
        copy_range(temp, s, start, last_non_blank);

        /* Print the folded thing */
        printf("%s\n", temp);
    }
    

    /* Recurse my brother */
    if (end_of_line != 0) fold(s, len, last_non_blank+1, col_stop);
}

/* copy_range: copy a range of chars from 'from' into 'to' */
void copy_range(char to[], char from[], int start, int end) {
    int i;

    for (i = 0; i+start <= end; ++i) {
        to[i] = from[i+start];
    }
    to[i] = '\0';
}