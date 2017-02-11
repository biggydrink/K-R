/*
 * remcomments.c
 *
 *  Created on: Jun 4, 2015
 *      Author: andre_000
 */

/* K&R Exercise 1-23
 * "Write a program to remove all comments from a C program. Don't forget to handle quoted strings and
 * character constants properly. C comments do not nest.
 */

/* First thoughts: So far in this book I think we've only seen comments appear with /* and ending
 * with *_/. So for now we'll go with just removing those comments. Eclipse lets me use // for
 * single line comments as well. We'll see if what I come up with for /* can be applied to // as well.
 */

/* 6/13/15: Managed to make this work for both /* comments and // comments. The if statements are a bit
 * much maybe, but easy enough to follow and the program works! The only thing I don't understand is that
 * I can't get nProgram to print using printf() - I have to do a for loop with putchar() instead. Other
 * than that, I think this is done.
 */

#include <stdio.h>
#define LIMIT 10000 /* Not sure yet how to make char strings with unlimited lengths */
#define IN 0
#define OUT 1

int getProgram(char program[]);

/* removes comments from C programs */
int main () {
	char program[LIMIT];
	char nProgram[LIMIT];
	int len; /* length of program */
	int i;
	int comments; /* in or out of a comment field */
	int slashc; // in a // comment

	len = getProgram(program);
	//printf("%d\n%s\n",len,program);

	comments = OUT;
	for (i = 0; i < len-1; ++i) {
		/* For comments beginning with /* and ending with */
		if (program[i] == '/' && program[i + 1] == '*')
			comments = IN;
		if (program[i] == '*' && program[i + 1] == '/') {
			comments = OUT;
			i += 2;
		}
		// For comments beginning with // and ending with a newline char
		if (program[i] == '/' && program [i+1] == '/')
			slashc = IN;
		if (slashc == IN && program[i] == '\n')
			slashc = OUT;
		/* If not within either type of comment, program copies to nProgram */
		if (comments == OUT && slashc == OUT)
			nProgram[i] = program[i];
	}

	for (i = 0;i<len;++i)
		putchar(nProgram[i]);

	printf("%s",nProgram);
	return 0;
}

int getProgram(char program[]) {

	int c, i;

	i = 0;
	while ((c = getchar()) != EOF && i < LIMIT) {
		program[i] = c;
		++i;
	}

	program[i] = '\0';

	return i;
}
