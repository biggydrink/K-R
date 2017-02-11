/*
 * linefold.c
 *
 *  Created on: May 25, 2015
 *      Author: andre_000
 */

/* K&R Exercise 1-22
 * "Write a program to 'fold' long input lines into two or more shorter lines after the last non-blank
 * character that occurs before the n-th column of input. Make sure your program does something
 * intelligent with very long lines, and if there are no blanks or tabs before the specified column."
 */

/* First thoughts:
 * Seems easiest to write a simple line-folding program, then add functionality afterwards, like
 * handling very long lines and when there are no blanks. I'll set the n-th column, initially, to
 * something small, so it's easy to test.
 */

/* 5/28/15
 * I think this is pretty complete, seems to work in all cases--whether with spaces or not, and when
 * the line is longer than either maxcol or maxline.
 */

#include <stdio.h>
#define MAXCOL 15
#define MAXLINE 1000

int getline(char line[], int lim);
int split(char line[], char newline[]);

/* Wraps long lines of input into two or more lines. */
int main() {
	int len;
	char line[MAXLINE];
	char newline[MAXLINE];

	len = getline(line,MAXLINE);
	len = split(line,newline);
	printf("%d, %s",len,newline);

	return 0;
}

/* Gets the length of a user-inputted line. The argument is a char[] that takes the input of the line.
 * The length of the line is returned as an int.
 */
int getline(char line[], int lim) {
	int c, i, j;

	j = 0;
	for (i = 0; ((c = getchar()) != EOF && c != '\n'); ++i) {
		if (i < lim-2) {
			line[j] = c;
			++j;
		}
	}
	if (c == '\n') {
		line[j] = c;
		++i;
		++j;
	}
	if (i > j)
		printf("The line was greater than the max length of %d. %d characters were omitted.\n",lim,(i-j));
	line[j] = '\0';
	return i;
}

/* Takes a line and splits it into multiple lines of MAXCOL+ characters each. Breaks lines on blanks
 * so words are not interrupted. If no blanks are encountered for 20 characters after MAXCOL, a '-' is
 * added to the line, then the next line is started anyway.
 * Returns the length of the current line.
 *
 * Idea: Currently the blank where the line breaks is the first character in the following new line
 * 		Maybe we do not want this character
 *
 * Idea: Could also make a status variable to tell when the line is in a word or not, and have the
 * 		blank be the last character of the old line instead of the first character of the new line.
 */
int split(char line[], char newline[]) {
	int counter; /* counter for the original line, line[] */
	int lines; /* counter for number of new lines, 0 means same as original (1 line) */
	int linec; /* counter for the current (split) line, newline[] */

	lines = linec = 0;
	for (counter = 0; line[counter] != '\0'; ++counter) {
		newline[counter + lines] = line[counter];
		++linec;
		if (linec > MAXCOL && (newline[counter + lines] == ' ' || newline[counter + lines] == '\t')) {
			++lines;
			newline[counter+lines] = '\n';
			linec = 0;
		} else if (linec > MAXCOL + 20) {
			++lines;
			newline[counter + lines] = '-';
			++lines;
			newline[counter + lines] = '\n';
			linec = 0;
		}
	}
	newline[counter + lines] = '\0';

	return (counter + lines);
}
