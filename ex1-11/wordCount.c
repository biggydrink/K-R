/*
 * wordCount.c
 *
 *  Created on: Apr 22, 2015
 *      Author: andre_000
 */

#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */

/* count lines, words, and characters in input */

/* exercise is to think of how to test
 * -input of only ' ' or only '\t' gives incorrect output of 0 0 0
 *
 */

main() {

	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
