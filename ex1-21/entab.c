/*
 * entab.c
 *
 *  Created on: May 14, 2015
 *      Author: andre_000
 */

/* K&R Exercise 1-21
 * Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks
 * to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single
 * blank would suffice to reach a tab stop, which should be given preference?
 */

/* First thoughts:
 * The question says "Use the same tab stops as for detab" - I suppose that could just mean the same
 * number of columns used in detab, but maybe it means to get the tab stops value from detab? Let's
 * do it that way at least for practice.
 * As for whether a single space or a tab should be used, I think just a single space should be used,
 * since it's more clear that it will be just one space, whereas a tab is sometimes longer.
 */

#include <stdio.h>
#define COL	4	/* number of spaces per tab stop */
#define IN 1	/* in a word */
#define OUT 0	/* not in a word */
void putspaces(int count, int blanks);

int main() {

	int c;
	int blanks; 	/* number of consecutive blanks */
	int count; 		/* length of current input line */
	int status;		/* determines if within a word (IN) or not (OUT) */

	count = 0;
	status = IN;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			status = OUT;
			++blanks;
			++count;
		} else {
			if (status == OUT)
				putspaces(count, blanks);
			status = IN;
			blanks = 0;
			putchar(c);
			++count;
		}
		if (c == '\n') {
			count = 0;
			blanks = 0;
		}
	}
	return 0;

}
/* takes current line position and consecutive spaces, and inputs tabs and spaces together
 * to get to the same spacing
 * Should be called at the end of a run of consecutive spaces
 */
void putspaces(int count, int blanks) {

	int ccount; /* current count, aka current place in the line */
	int rblanks; /* remaining blanks, aka blanks - tabs/blanks entered */
	int tabspace; /* number of spaces in a tab from current position */

	ccount = count - blanks;

	while (ccount < count) {
		tabspace = COL - (ccount % COL);
		rblanks = count - ccount;
		if (tabspace <= rblanks && tabspace != 1) {
			putchar('\t');
			ccount += tabspace;
		} else {
			putchar(' ');
			++ccount;
		}

	}

	/* A for loop implementation of this function
	 * I chose to use the while loop in this case because I think the code is clearer/easier to follow

	for (ccount = count - blanks; ccount < count;) {
		tabspace = COL - (ccount % COL);
		rblanks = count - ccount;
		if (tabspace <= rblanks && tabspace != 1) {
			putchar('\t');
			ccount += tabspace;
		} else {
			putchar(' ');
			++ccount;
		}
	}
	*/
}
