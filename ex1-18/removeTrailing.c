/*
 * removeTrailing.c
 *
 *  Created on: May 5, 2015
 *      Author: andre_000
 */

#include <stdio.h>
#define MAXLINE	1000	/* maximum input line size */

int gettheline(char line[], int maxline);
void copy(char to[], char from[]);

/* K&R - Exercise 1-18
 * Write a program to remove trailing blanks and tabs from each line of input, and to delete
 * entirely blank lines */
int main() {

	int len;		/* current line length */
	int max;		/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = gettheline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest,line);
		}
	}
	if (max > 0)		/* there was a line */
		printf("Length: %d\nLine: %s", max, longest);
	return 0;
}

/* gettheline:		read a line into s, return length */
int gettheline(char s[], int lim) {

	int c, i;
	int endLine;	/* 1 for Yes, 0 for No */

	endLine = 0;
	for (i = 0; i<lim-1 && ((c=getchar())!=EOF && c!='\n'); ++i)
		s[i] = c;
	if (c == '\n')
		endLine = 1;

	--i;
	while (s[i] == '\t' || s[i] == ' ') {
		--i;
	}

	if (endLine == 1) {
		++i;
		s[i] = '\n';
	}
	++i;
	s[i] = '\0';
	return i;
}

/* copy:	copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {

	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
