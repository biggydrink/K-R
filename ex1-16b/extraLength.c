/*
 * extraLength.c
 *
 *  Created on: Apr 30, 2015
 *      Author: andre_000
 */

#include <stdio.h>
#define MAXLINE	5	/* maximum input line size */

int gettheline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {

	int len;		/* current line length */
	int max;		/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = gettheline(line, MAXLINE)) > 0) {
		printf("%d, %s", len, line);
		if (len > max) {
			max = len;
			copy(longest,line);
		}
	}
	if (max > 0)		/* there was a line */
		printf("%s", longest);
	return 0;
}

/* gettheline:		read a line into s, return length */
int gettheline(char s[], int lim) {

	int c, i, j;

	j = 0;
	for (i = 0; ((c=getchar())!=EOF && c!='\n'); ++i)
		if (i < lim-2) {
			s[j] = c;
			++j;
		}
	if (c == '\n') {
		s[j] = c;
		++i;
		++j;
	}
	s[j] = '\0';
	return i;
}

/* copy:	copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {

	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
