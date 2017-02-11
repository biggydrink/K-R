/*
 * eightyPlusOnly.c
 *
 *  Created on: May 6, 2015
 *      Author: andre_000
 */


#include <stdio.h>

#define MAXLINE	1000 /* maximum line length */

int gettheline(char line[], int maxline);
void copy(char to[], char from[]);

/* print all input lines that are 80 characters or longer */
/* version 1 - print each 80+ line immediately after input, then print longest line */
/* version 2 (below) - print all 80+ lines at the end, no record of longest line?
 * maybe save lines in an array, up to a certain amount I suppose
 */

/* 5/6/15 Update:
 * Putting char arrays inside of another char array does not seem to work
 * Maybe come back to this after you find out how to put char arrays inside other arrays.
 */

main() {
	int len;				/* current line length */
	int count;				/* current number of 80+ lines */
	int i;
	char line[MAXLINE];		/* current line */
	char eighty[MAXLINE];	/* longest line saved here */


	while ((len = gettheline(line, MAXLINE)) > 0) {
		if (len > 80)
			copy(eighty[count],line);
			++count;
	}
	printf("There were %d lines with more than 80 lines",count);
	for (i = 0; i < count; ++i) {
		printf("Line %d: %s",i+1,eighty[i]);
	}
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

