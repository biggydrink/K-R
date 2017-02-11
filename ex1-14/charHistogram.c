/*
 * charHistogram.c
 *
 *  Created on: Apr 26, 2015
 *      Author: andre_000
 */

#include <stdio.h>

/* creates a horizontal histogram of the frequency of the characters in its input
 * uses ASCII code for character info */

main () {

	int c, i, j;
	int chars[127];

	for (i = 0; i < 127; ++i)
		chars[i] = 0;

	while ((c = getchar()) != EOF) {
		++chars[c];
	}
	for (i = 0; i < 127; ++i) {
		printf("%3d\t",i);
		//printf("%3d\t%2d",i,chars[i]);
		for (j = 0; j < chars[i]; ++j)
			putchar('|');
		putchar('\n');
	}
}
