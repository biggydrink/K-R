/*
 * singleBlank.c
 *
 *  Created on: Apr 12, 2015
 *      Author: andre_000
 */

/* copy input to output, and replace each string of 2 or more blanks with just one blank
 * on Windows, to end program (input EOF) press ctrl+z on its own line in DOS, then hit enter
 */

#include <stdio.h>

main() {
	int c;
	long bl;

	bl = 0;

	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			bl = 0;
			putchar(c);
		}
		if (c == ' ') {
			++bl;
			if (bl <= 1) {
				putchar(c);
			}
		}
	}
}
