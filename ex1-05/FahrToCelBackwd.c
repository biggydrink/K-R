/*
 * FahrToCelBackwd.c
 *
 *  Created on: Apr 7, 2015
 *      Author: andre_000
 */

#include <stdio.h>

/* displaying Fahrenheit converted to Celsius, from 300 to 0, step -20 */
/* For exercise 1-5 in K&R (page 14) */
/* Builds on exercises 1-3 and 1-4, but uses a for loop instead of a while loop */

main() {
	int fahr;

	for (fahr=300; fahr>=0; fahr = fahr - 20) {
		printf("%3d %6.1f\n",fahr,(5.0/9.0) * (fahr-32));
	}
}
