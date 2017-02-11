/*
 * histogramHorz.c
 *
 *  Created on: Apr 23, 2015
 *      Author: andre_000
 */

#include <stdio.h>

#define IN	1	/* in a word */
#define OUT	0	/* not in a word */

/* create a historgram of the lengths of words in the input. Histogram
 * goes horizontally.
 */

main() {

	int c, wchars, state, i;

	state = OUT;
	wchars = i = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (wchars > 0) {
				putchar(' ');
				for (i = 0; i < wchars; ++i) {
					putchar('|');
				}
			}
			printf(" %d",wchars);
			wchars = 0;
			putchar('\n');
		} else {
			state = IN;
			++wchars;
			putchar(c);
		}
	}
}
