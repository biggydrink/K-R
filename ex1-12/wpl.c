/*
 * wpl.c
 *
 *  Created on: Apr 22, 2015
 *      Author: andre_000
 */

#include <stdio.h>

#define IN	1 /* inside a word */
#define OUT	2 /* outside a word */

/* takes input and prints the output one word per line */
/* variable nl and the if statement around it don't appear to be working
 * also, the variable state may not be necessary
 */

main() {

	int c, nl, state;

	nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			++nl;
			if (nl <= 1)
				putchar('\n');
		}
		else
			putchar(c);
			nl = 0;
			if (state == OUT)
				state = IN;
	}
}
