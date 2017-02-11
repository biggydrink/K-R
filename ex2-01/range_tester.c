/*
 * range_tester.c
 *
 *  Created on: Jun 14, 2015
 *      Author: andre_000
 */

/* K&R Exercise 2-1
 * "Write a program to determine the ranges of char, short, int, and long variables, both signed and
 * unsigned, by printing appropriate values from standard headers and by direct computation. Harder if
 * you compute them: determine the ranges of the various floating-point types."
 */

/* First thoughts:
 * The standard headers are limits.h and float.h. I think I'll start with the easy way, of just printing
 * the minimums and maximums. Not exactly sure how to go about determining the ranges by direct
 * computation, but I'll see what happens when you try to assign (or maybe print) values that exceed
 * the limits specified in these two headers.
 */
#include <stdio.h>
#include <limits.h>
#include <float.h> // learned that these must all be on separate lines

int main() {

	/* char constants - interesting to note that these are all int variables, not chars */
	printf("Char constants\n");
	printf("Bits in a char: %d\n",CHAR_BIT);
	printf("Default max value of char (signed or unsigned?): %d\n",CHAR_MAX);
	printf("Max value of unsigned char: %d\n",UCHAR_MAX);
	printf("Max value of signed char: %d\n",SCHAR_MAX);
	printf("Default min value of char: %d\n",CHAR_MIN);
	printf("Min value of unsigned char: %d\n",SCHAR_MIN);
	printf("Max value of signed char: %d\n",SCHAR_MAX);

	/* int constants */
	printf("\nInt constants, including short and long\n");
	printf("Max value of int: %d\n",INT_MAX);
	printf("Max value of unsigned int: %d\n",UINT_MAX);
	printf("Min value of int: %d\n",INT_MIN);
	printf("Max value of (int) long: %ld\n",LONG_MAX);
	printf("Max value of unsigned (int) long: %ld\n",ULONG_MAX);
	printf("Min value of (int) long: %ld\n",LONG_MIN);
	printf("Max value of (int) short: %d\n",SHRT_MAX);
	printf("Max value of unsigned (int) short: %d\n",USHRT_MAX);
	printf("Min value of (int) short: %d\n",SHRT_MIN);

	/* float constants */
	printf("\nFloat Constants\n");
	printf("Radix of exponent representation: %d\n",FLT_RADIX);
	printf("Floating-point rounding mode for addition: %d\n",FLT_ROUNDS);
	printf("Decimal digits of precision: %d\n",FLT_DIG);
	printf("Smallest number x such that 1.0 + x != 1.0: %.25f\n",FLT_EPSILON);
	printf("Number of base FLT_RADIX digits in mantissa: %d\n",FLT_MANT_DIG);
	printf("Maximum floating-point number: %.25f\n",FLT_MAX);
	printf("Maximum n such that (FLT_RADIX^n)-1 is representable: %d\n",FLT_MAX_EXP);
	printf("Minimum normalized floating-point number: %.25f\n",FLT_MIN);
	printf("Minimum n such that 10^n is a normalized number: %d\n",FLT_MIN_EXP);

	/* double constants*/
	printf("\nDouble Constanats\n");
	printf("Decimal digits of precision: %d\n",DBL_DIG);
	printf("Smallest number x such that 1.0 + x != 1.0: %.25f\n",DBL_EPSILON);
	printf("Number of base FLT_RADIX digits in mantissa: %d\n",DBL_MANT_DIG);
	printf("Maximum n such that (FLT_RADIX^n)-1 is representable: %d\n",DBL_MAX_EXP);
	printf("Minimum normalized double floating-point integer: %.25f\n",DBL_MIN);
	printf("Minimum n such that 10^n is a normalized number: %d\n",DBL_MIN_EXP);

	return 0;
}
