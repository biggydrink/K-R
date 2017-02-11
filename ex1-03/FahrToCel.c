/*
 * FahrToCel.c
 *
 *  Created on: Apr 2, 2015
 *      Author: andre_000
 */

#include <stdio.h>

/* print Fahrenheit-Celsius table for fahr = 0, 5, ..., 120 */

main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature table */
	upper = 120; 	/* upper limit */
	step = 5;		/* step size */

	fahr = lower;

	printf("Fahrenheit to Celsius\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
