/*
 * CelToFahr.c
 *
 *  Created on: Apr 7, 2015
 *      Author: andre_000
 */

#include <stdio.h>

/* print Celsius-Fahrenheit table for celsius = 0, 2, ..., 44 */

main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; /* lower limit of temperature table */
	upper = 44; /* upper limit */
	step = 2; /* step size */

	celsius = lower;

	printf("Celsius to Fahrenheit:\n");
	while (celsius <= upper) {
		fahr = celsius * (9.0/5.0) + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
