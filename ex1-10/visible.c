/*
 * visible.c
 *
 *  Created on: Apr 12, 2015
 *      Author: andre_000
 */

/* copies input to output
 * shows each tab as \t, each backspace as \b, each backslach as \\
 */

#include <stdio.h>

main() {
	int c;
	long tab, bspc, slash, nl;

	tab = '\t';
	bspc = '\b';
	slash = '\'';
	nl = '\n';

	while ((c = getchar()) != EOF) {
		if (c == tab) {
			c = '\\';
			putchar(c);
			c = 't';
		}
		if (c == bspc) {
			c = '\\';
			putchar(c);
			c = 'b';
		}
		if (c == slash) {
			c = '\\';
			putchar(c);
			c = '\\';
		}
		if (c == nl) {
			c = '\\';
			putchar(c);
			c = 'n';
		}
		putchar(c);
	}
}
