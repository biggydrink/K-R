/*
 * reverseans.c
 *
 *  Created on: May 11, 2015
 *      Author: andre_000
 */

#include <stdio.h>
#define MAXLINE	1000	/* maximum input line size */

int gettheline(char line[], int maxline);
void reverse(char s[]);

/* Exercise 1-19
 * Write a function reverse(s) that that reverses the character string s. Use it to write a program
 * that reverses its input one line at a time
 *
 * This is the program from the answer key. I'm having a hard time following the use of the temp
 * variable, so I want to debug it*/
int main() {

	int len;		/* current line length */
	char line[MAXLINE];		/* current input line */

	while ((len = gettheline(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s\n",line);
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

void reverse(char s[]) {

	int i, j;
	char temp;

	i = 0;
	while (s[i] != '\0')		/* find the end of string s */
		++i;
	--i;						/* back off from '\0' */
	if (s[i] == '\n')
		--i;					/* leave newline in place */

	j = 0;
	while (j < i) {
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
		--i;
		++j;
	}
}
