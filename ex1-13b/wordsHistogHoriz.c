/*
 * wordsHistogHoriz.c
 *
 *  Created on: Apr 24, 2015
 *      Author: andre_000
 */

#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */

/* Takes input and makes a histogram of the lengths of words in the input, from 1 to 10+
 * Histogram is horizontal
 */

main() {

	int c, wcc, i, j;
	int words[11];

	wcc = 0;

	for (i = 0; i < 11; ++i)
		words[i] = 0;

	while ((c = getchar()) != EOF) {

		if (c == ' ' || c == '\t' || c == '\n') {
			if (wcc > 0) {
				if (wcc > 10)
					wcc = 10;
				++words[wcc];
			}
			wcc = 0;
		} else {
			++wcc;
		}
	}
	for (i = 1; i < 11; ++i) {
		printf("%d\t",i);
		for (j = 0; j < words[i]; ++j)
			putchar('|');
		putchar('\n');
	}
}
