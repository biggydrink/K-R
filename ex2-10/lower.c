/*
 * lower.c
 *
 *  Created on: Jul 15, 2015
 *      Author: andre_000
 */

/* K&R Exercise 2-10, 7/15/15
 * Rewrite the funtion lower, which converts upper case letters to lower case, with a conditional
 * expression instead of if-else.
 *
 * Function lower(), from section 2.7:
 * * lower: convert c to lower case; ASCII only *
 * int lower(int c) {
 * 		if (c >= 'A' && c <= 'Z')
 * 			return c + 'a' - 'A';
 * 		else
 * 			return c;
 * 	}
 */

/* First thoughts, 7/15/15
 * Seems fairly straightforward, although I wouldn't be surprised if there was something about it that
 * made it harder than it initially looks...
 *
 * Conditional expression is
 *
 * expr1 ? expr2 : expr3
 */

#include <stdio.h>

int lower(int c);

int main(void) {
	int c;

	c = 'K';
	c = lower(c);
	putchar(c);

	return 0;
}

int lower(int c) {

	c = (c >= 'A' && c<= 'Z') ? c + 'a' - 'A' : c;
	return c;
}

