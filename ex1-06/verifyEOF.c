/*
 * verifyEOF.c
 *
 *  Created on: Apr 8, 2015
 *      Author: andre_000
 */

#include <stdio.h>

main() {
	int c;

	c = (getchar() != EOF);
	printf("%d",c);

}
