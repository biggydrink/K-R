/*
 * CelToFahr.c
 *
 *  Created on: Apr 7, 2015
 *      Author: andre_000
 */

/*
 * Adding Symbolic Constants to exercise 1-5
 * Print Celsius to Fahrenheit table
 */

#include <stdio.h>

#define	LOWER	0		/* lower limit of table */
#define	UPPER	50		/* upper limit of table */
#define	STEP	5		/* step size */

main () {
	int celsius;

	for (celsius=LOWER; celsius <= UPPER; celsius = celsius + STEP) {
		printf("%3d\t%6.1f\n", celsius, celsius * (9.0/5.0) + 32.0);
	}
}
