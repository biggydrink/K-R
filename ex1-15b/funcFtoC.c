/*
 * funcFtoC.c
 *
 *  Created on: Apr 27, 2015
 *      Author: andre_000
 */

#include <stdio.h>

float ftoC(float f);

/* rewrite of the temperature conversion program from section 1.2 to include a function
 * takes fahrenheit input and converts to celsius, for each step up to the limit
 */
main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temperature table */
	upper = 120; 	/* upper limit */
	step = 5;		/* step size */

	fahr = lower;

	printf("Fahrenheit to Celsius\n");
	while (fahr <= upper) {
		celsius = ftoC(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

/* FtoC: takes fahrenheit int input and converts it to celsius */
float ftoC(float f) {

	float c;

	c = (5.0/9.0) * (f-32.0);
	return c;
}
