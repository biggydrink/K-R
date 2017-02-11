/*
 * reverse.c
 *
 *  Created on: May 6, 2015
 *      Author: andre_000
 */

#include <stdio.h>
#define MAXLINE	1000	/* maximum input line size */

int gettheline(char line[], int maxline);
void reverse(char s[], int length, char to[]);

/* Exercise 1-19
 * Write a function reverse(s) that that reverses the character string s. Use it to write a program
 * that reverses its input one line at a time */
int main() {

	int len;		/* current line length */
	char line[MAXLINE];		/* current input line */
	char revLine[MAXLINE];	/* the reverse of the current input line */

	while ((len = gettheline(line, MAXLINE)) > 0) {
		reverse(line,len,revLine);
		printf("Original: %sReverse: %s\n",line,revLine);
	}
	return 0;
}

/* gettheline:		read a line into s, return length */
int gettheline(char s[], int lim) {

	int c, i;

	for (i = 0; i<lim-1 && ((c=getchar())!=EOF && c!='\n'); ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[], int length, char to[]) {

	int i, j;

	j = 0;
	for (i = length-2; i >= 0; --i) {
		to[j] = s[i];
		++j;
	}
	to[j] = '\n';
	to[j+1] = '\0';
}
