/*
 * counting.c
 *
 *  Created on: Apr 12, 2015
 *      Author: andre_000
 */

/* counts and prints blanks, tabs, and new line inputs
 * in Windows, press ctrl+z on a new line in cmd and hit enter to end program (EOF)*/

#include <stdio.h>

main()
{
	int c;
	long nl, bl, tab;

	nl = 0;
	bl = 0;
	tab = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
		if (c == ' ')
			++bl;
		if (c == '\t')
			++tab;
	}

	printf("\nnewlines: %ld\nblanks: %ld\ntabs: %ld",nl,bl,tab);
}
