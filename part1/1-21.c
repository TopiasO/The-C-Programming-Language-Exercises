#include <stdio.h>
#define MAXLINE 1000        /* maximum input line size */
#define N 8                 /* Lets say that a tab stop appears every five columns */
#define IN 1    /* inside a string of blanks */
#define OUT 0   /* outside a string of blanks */

int b_t[3];     /* how many blanks and tabs can replace a string of blanks */

int getline1(char line[], int maxline);
void copy(char to[], char from[]);
void entab(char line[], char temp[], int length);
void delete_range(char line[], char temp[], int start, int len, int diff);
void blanks_to_tabs(int position, int blanks);
void replace_blanks(char line[], char temp[], int position, int len);

/* Write a program to entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use the
same tab stops as for detab.*/

int main() {
    int len;                /* current line length */                    
    char line[MAXLINE];     /* current input line */
    char temp[MAXLINE];     /* temp store for line */

    while ((len = getline1(line, MAXLINE)) > 0) {
        copy(temp, line);
        entab(line, temp, len);
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

/* entab: replace strings of blanks in s with the minimum amount
of tabs and blanks */
void entab(char s[], char temp[], int length) {
    int i, diff, blanks, state;

    state = IN;
    blanks = 0;
    diff = 0;
    for (i = 0; i <= length; ++i) {
        if (temp[i] == ' ') {
            state = IN;
            ++blanks;
        } else if (state == IN) {
            if (blanks >= 1) {
                delete_range(s, temp, i-blanks, blanks, diff);
                blanks_to_tabs(i-blanks, blanks);
                replace_blanks(s, temp, i-blanks-diff, blanks);
                diff += blanks - (b_t[0] + b_t[1] + b_t[2]);
            }
            blanks = 0;
            s[i-diff] = temp[i];
        }
    }
}

/* delete_range: delete substring of s from s[start] to s[start+len]
move the rest of the string to continue at s[start+1] */
void delete_range(char s[], char temp[], int start, int len, int diff) {
    int i;

    i = 0;
    while ((s[i+start-diff] = temp[i+start+len]) != '\0') 
        ++i;
}

/* blanks_to_tabs: count how many tabs and blanks can replace a
string of blanks starting from the given position. Return diff to original string */
void blanks_to_tabs(int pos, int blanks) {
    int to_next_stop, len;
    extern int b_t[];   /* b_t[0]=blanks before tabs, b_t[1]=blanks, b_t[2]=blanks after*/

    b_t[0] = (b_t[1] = 0);
    b_t[2] = blanks;

    to_next_stop = N - (pos % N);

    if (to_next_stop > 1 && blanks > to_next_stop) {
        b_t[1] += 1;
        b_t[2] -= to_next_stop;
    } else {
        b_t[0] = 1;
        b_t[2] -= 1;
    }

    b_t[1] += b_t[2] / N;
    b_t[2] = b_t[2] % N;
    /* Length of tabs and blanks 
    len = b_t[0] + b_t[1] + b_t[2];

    /* Return the difference between tabless and entabbed substring
    return blanks - len; */
}


/* replace_blanks: add blanks, tabs, and blanks from 'b_t' to 's', starting
from 'position'. Move the rest of 's' to continue after the blanks and tabs */
void replace_blanks(char s[], char temp[], int position, int blanks) {
    int i;
    extern int b_t[];

    i = 0;
    if (b_t[0] == 1) s[position] = ' ';

    for (i = 0; i <= b_t[1]+b_t[2]; ++i) {
        if (i < b_t[1]) s[i+position] = '\t';
        else s[i+position] = ' ';
    }
}

