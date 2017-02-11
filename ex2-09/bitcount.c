/*
 * bitcount.c
 *
 *  Created on: Jul 12, 2015
 *      Author: andre_000
 */

/* K&R Exercise 2-9
 * In a two's complement number system, x&= (x-1) deletes the rightmost 1-bit in x. Explain why.
 * Use this observation to write a faster version of bitcount.
 *
 * bitcount(unsigned x) {
 * int b;
 *
 * for (b = 0; x != 0; x >>=1)
 * 		if (x & 01)
 * 			b++;
 * return b;
 * }
 */

/* First thoughts, 7/12/15
 * Seems to me like the reason why x &= (x-1) deletes the rightmost 1-bit in x is because subtracting
 * 1 from a number changes the rightmost bit (either from 0 to 1 or from 1 to 0), and thus when you
 * also do an & operation with x and the changed bit, that bit becomes a 0 (as they are not the same).
 *
 * Not sure yet how to make that into a faster version of bitcount though.
 */

/* Second thoughts, 7/15/15
 * Turns out I didn't quite have this correct - I was thinking that x &= (x-1) changed the rightmost bit
 * to a 0, if it was 1. But no, it changes whatever the rightmost-1-bit is to 0, i.e. 1100 would become
 * 1000. The reasoning is basically the same though - it has to do with the fact that in binary, a
 * number has to move up one place as soon as it's greater than 1, so it's either 0 or 1. Basically
 * the same reason as above, except it applies to the rightmost 1-bit only--subtracting by 1 will
 * make whatever the rightmost 1 bit is to a 0, and therefore no matter how many 1-bits are to the
 * right of that new 0, if you & the number with the original, they would all resolve to 0's, as no two
 * of them will be 1's.
 *
 * With that in mind, the program would just be a loop of the command "x &= (x-1)" and the answer is how
 * many times the loop executed before x became 0.
 */

#include <stdio.h>

int bitcount(unsigned x);

int main(void) {
	int x; /* any number */
	int bits;

	x = 31999;

	bits = bitcount(x);

	printf("%d 1-bits in %d",bits,x);

	return 0;
}

/* bitcount()
 * count 1 bits in x
 */
int bitcount(unsigned x) {

	int b;

	for (b=0; x != 0; ++b)
		x &= (x-1);

	return b;
}
