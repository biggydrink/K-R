/*
 * power.c
 *
 *  Created on: Apr 27, 2015
 *      Author: andre_000
 */

#include <stdio.h>

int power(int m, int n);

/* 	exercise from the book to illustrate functions
	tests the Power function */
main() {

	int i;

	for (i = 0; i <= 20; ++i)
		printf("%2d\t%7d\n", i, power(2,i));
	return 0;
}

/* power: raise base to n-th power; n >= 0 */
int power(int base, int n) {

	int i, p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}
