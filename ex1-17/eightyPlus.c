/*
 * eightyPlus.c
 *
 *  Created on: May 4, 2015
 *      Author: andre_000
 */

#include <stdio.h>

#define MAXLINE	1000 /* maximum line length */

int gettheline(char line[], int maxline);
void copy(char to[], char from[]);

/* print all input lines that are 80 characters or longer */
/* version 1 (below) - print each 80+ line immediately after input, then print longest line */
/* version 2 - print all 80+ lines at the end, no record of longest line?
 * maybe save lines in an array, up to a certain amount I suppose
 */

int main() {
	int len;				/* current line length */
	int max;				/* longest line length seen so far*/
	char line[MAXLINE];		/* current line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = gettheline(line, MAXLINE)) > 0) {
		if (len > 80)
			printf("80+: %d, %s",len, line);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) 	/* there was a line */
		printf("Longest Length: %d\nLongest String: %s",max,longest);
	return 0;
}

/* gettheline: reads a line into s, returns length */
int gettheline(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


/* copy char string from[] to char string to[]. Assume to[] is long enough */
void copy(char to[], char from[]) {

	int i;

	//i = 0;
	//while ((to[i] = from[i]) != '\0')
	//	++i;
	for (i = 0; from[i] != '\0'; ++i) {
		to[i] = from[i];
	}
}

